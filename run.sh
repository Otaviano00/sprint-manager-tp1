#!/bin/bash
set -euo pipefail

# Compila e executa um projeto C/C++ seguindo estas regras:
# - Sem flags: tenta localizar src/**/main.(c|cpp|cc|cxx|c++)
# - Com -m: usa o caminho do arquivo principal informado
# - Compila todos os .c/.cpp (recursivo) dentro de src/ (e extras do bib.txt)
# - Binário vai para bin/Debug (debug) ou bin/Release (release)

shopt -s nullglob

#==============================================================================
# VARIÁVEIS GLOBAIS
#==============================================================================
MAIN_PATH=""
BIB_FILE=""
NEED_INPUT=false
RUN=true
BUILD_TYPE="Release"   # Release | Debug

ROOT=""
SRC_DIR=""

MAIN_FILE=""
OUT_NAME=""

declare -a BIB_COMPILE_FLAGS=()
declare -a BIB_LINK_FLAGS=()
declare -a BIB_EXTRA_SOURCES=()

#==============================================================================
# FUNÇÕES
#==============================================================================
resolve_path() {
  local p="$1"
  if command -v realpath >/dev/null 2>&1; then
    realpath "$p"
    return
  fi
  if command -v readlink >/dev/null 2>&1; then
    readlink -f "$p"
    return
  fi

  # Fallback simples (não resolve symlink).
  (cd "$(dirname "$p")" && printf '%s/%s\n' "$(pwd)" "$(basename "$p")")
}

is_source_file() {
  local p="$1"
  case "${p,,}" in
    *.c|*.cpp|*.cc|*.cxx|*.c++) return 0 ;;
    *) return 1 ;;
  esac
}

is_cpp_file() {
  local p="$1"
  case "${p,,}" in
    *.cpp|*.cc|*.cxx|*.c++) return 0 ;;
    *) return 1 ;;
  esac
}

is_compile_flag() {
  local f="$1"
  case "$f" in
    -I*|-D*|-U*|-std=*|-W*|-f*|-O*|-g|-pthread) return 0 ;;
    *) return 1 ;;
  esac
}

read_depfile_deps() {
  local depfile="$1"
  # Lê apenas a primeira regra do arquivo .d (as dependências reais).
  # Ignora as regras "dummy" geradas por -MP (linhas do tipo "header.hpp:").
  # Observação: assume que os caminhos não contêm espaços.
  awk '
    NR==1 { sub(/^[^:]+:[[:space:]]*/, ""); }
    NR==1 || /^[[:space:]]/ {
      gsub(/\\$/, "");
      for (i=1; i<=NF; i++) if ($i != "") print $i;
      next
    }
    { exit }
  ' "$depfile"
}

needs_recompile() {
  local src="$1"
  local obj="$2"
  local depfile="$3"
  local dependency

  if [ ! -f "$obj" ]; then
    return 0
  fi
  if [[ "$src" -nt "$obj" ]]; then
    return 0
  fi
  if [ ! -f "$depfile" ]; then
    return 0
  fi

  while IFS= read -r dependency; do
    # Ignora o próprio src/obj se aparecerem na lista
    [ -z "$dependency" ] && continue
    [ "$dependency" = "$src" ] && continue
    [ "$dependency" = "$obj" ] && continue

    # Se um header sumiu, recompila (dependências mudaram)
    if [ ! -e "$dependency" ]; then
      return 0
    fi
    if [[ "$dependency" -nt "$obj" ]]; then
      return 0
    fi
  done < <(read_depfile_deps "$depfile")

  return 1
}

show_help() {
  cat << EOF
Uso: $0 [opções]

Opções:
  Sem flag:     Roda o arquivo main.* que encontrar na pasta src/ (recursivo). Se encontrar mais que um, não executa.
  -m FILE       Caminho do arquivo principal. Ex: -m src/main2.cpp
  -b FILE       Arquivo com flags/arquivos extras (padrão: <root>/bib.txt)
  -i            Executa interativamente (aguarda input do usuário)
  Sem -i:       Redireciona in.txt para o programa e saída para out.txt
  -g            Compila em modo Debug e executa
  -d            Compila em modo Debug sem executar
  -h            Mostra esta ajuda

Exemplos:
  $0
  $0 -i
  $0 -g 
  $0 -m src/main.cpp
  $0 -m src/main.cpp -b bib.txt
EOF
  exit 0
}

#==============================================================================
# PROCESSAMENTO DE ARGUMENTOS
#==============================================================================
while getopts ":m:ib:hgd" opt; do
  case $opt in
    m)
      MAIN_PATH="$OPTARG"
      ;;
    i) 
      NEED_INPUT=true
      ;;
    b)
      BIB_FILE="$OPTARG"
      ;;
    h)
      show_help
      ;;
    g)
      BUILD_TYPE="Debug"
      ;;
    d)
      BUILD_TYPE="Debug"
      RUN=false
      ;;
    \?) 
      echo "Erro: Opção inválida -$OPTARG" >&2
      show_help
      ;;
    :) 
      echo "Erro: A opção -$OPTARG requer um argumento" >&2
      show_help
      ;;
  esac
done

#==============================================================================
# VALIDAÇÕES
#==============================================================================
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SRC_DIR="$ROOT/src"

if [ ! -d "$SRC_DIR" ]; then
  echo "Erro: pasta 'src' não encontrada em '$ROOT'." >&2
  exit 1
fi

if [ -z "$MAIN_PATH" ]; then
  # Sem -m: procura por src/**/main.(c|cpp|cc|cxx|c++)
  mapfile -t _MAIN_CANDIDATES < <(
    find "$SRC_DIR" -type f \( \
      -name "main.c" -o \
      -name "main.cpp" -o \
      -name "main.cc" -o \
      -name "main.cxx" -o \
      -name "main.c++" \
    \) -print
  )

  if [ "${#_MAIN_CANDIDATES[@]}" -eq 0 ]; then
    echo "Erro: não encontrado 'main.(c|cpp|cc|cxx|c++)' dentro de '$SRC_DIR'." >&2
    exit 1
  fi

  if [ "${#_MAIN_CANDIDATES[@]}" -gt 1 ]; then
    echo "Erro: mais de um main encontrado em '$SRC_DIR'. Use -m para escolher um:" >&2
    printf '  - %s\n' "${_MAIN_CANDIDATES[@]}" >&2
    exit 1
  fi

  MAIN_FILE="${_MAIN_CANDIDATES[0]}"
else
  MAIN_FILE="$(resolve_path "$MAIN_PATH")"
  if [ ! -f "$MAIN_FILE" ]; then
    echo "Erro: arquivo principal '$MAIN_PATH' não encontrado." >&2
    exit 1
  fi
  if ! is_source_file "$MAIN_FILE"; then
    echo "Erro: arquivo principal deve ser .c/.cpp/.cxx (recebi '$MAIN_PATH')." >&2
    exit 1
  fi
fi

OUT_NAME="$(basename "$MAIN_FILE")"
OUT_NAME="${OUT_NAME%.*}"


#==============================================================================
# CARREGAMENTO DE BIBLIOTECAS
#==============================================================================
if [ -z "$BIB_FILE" ]; then
  BIB_FILE="$ROOT/bib.txt"
fi

if [ ! -f "$BIB_FILE" ]; then
  # bib.txt é opcional
  :
else
  while IFS= read -r line; do
    # Ignora linhas vazias e comentários
    [[ -z "$line" || "$line" =~ ^[[:space:]]*# ]] && continue

    # Permite flags (ex: -lm, -lstdc++fs) e caminhos absolutos.
    if [[ "$line" == -* ]]; then
      BIB_LINK_FLAGS+=("$line")
      if is_compile_flag "$line"; then
        BIB_COMPILE_FLAGS+=("$line")
      fi
    elif [[ "$line" == /* ]]; then
      if is_source_file "$line"; then
        BIB_EXTRA_SOURCES+=("$line")
      else
        BIB_LINK_FLAGS+=("$line")
      fi
    else
      local_path="$ROOT/$line"
      resolved_path="$(resolve_path "$local_path")"
      if is_source_file "$resolved_path"; then
        BIB_EXTRA_SOURCES+=("$resolved_path")
      else
        BIB_LINK_FLAGS+=("$resolved_path")
      fi
    fi
  done < "$BIB_FILE"
fi

#==============================================================================
# COMPILAÇÃO
#==============================================================================
BIN_DIR="$ROOT/bin/$BUILD_TYPE"
OBJ_DIR="$ROOT/obj/$BUILD_TYPE"
mkdir -p "$BIN_DIR" "$OBJ_DIR"

declare -a SOURCES=()
mapfile -t SOURCES < <(
  find "$SRC_DIR" -type f \( \
    -name "*.c" -o -name "*.cpp" -o -name "*.cc" -o -name "*.cxx" -o -name "*.c++" \
  \) -print
)

if [ "${#SOURCES[@]}" -eq 0 ]; then
  echo "Erro: nenhum arquivo fonte encontrado em '$SRC_DIR'." >&2
  exit 1
fi

if [ "${#BIB_EXTRA_SOURCES[@]}" -gt 0 ]; then
  SOURCES+=("${BIB_EXTRA_SOURCES[@]}")
fi

# Se o main informado via -m estiver fora de src/, garante que ele será compilado.
if [[ "$MAIN_FILE" != "$ROOT/"* ]]; then
  SOURCES+=("$MAIN_FILE")
fi

HAS_CPP=false
for s in "${SOURCES[@]}"; do
  if is_cpp_file "$s"; then
    HAS_CPP=true
    break
  fi
done

# Includes automáticos: todas as pastas dentro de src/ (para facilitar #include "x.hpp")
declare -a AUTO_INCLUDE_FLAGS=()
while IFS= read -r incdir; do
  AUTO_INCLUDE_FLAGS+=("-I$incdir")
done < <(find "$SRC_DIR" -type d -print)

COMMON_FLAGS=()
if [ "$BUILD_TYPE" = "Debug" ]; then
  COMMON_FLAGS+=("-g" "-O0")
else
  COMMON_FLAGS+=("-O2" "-DNDEBUG")
fi

declare -a OBJECTS=()
echo "Compilando (main: $(basename "$MAIN_FILE"), build: $BUILD_TYPE)..."

for src in "${SOURCES[@]}"; do
  # Mantém subpastas (obj/<BuildType>/...)
  if [[ "$src" == "$ROOT/"* ]]; then
    rel="${src#$ROOT/}"
  else
    rel="external_${src#/}"
    rel="${rel//\//_}"
  fi
  obj="$OBJ_DIR/${rel%.*}.o"
  dep="$OBJ_DIR/${rel%.*}.d"
  mkdir -p "$(dirname "$obj")"

  if needs_recompile "$src" "$obj" "$dep"; then
    if [[ "${src,,}" == *.c ]]; then
      echo "  [CC ] $rel"
      gcc "${COMMON_FLAGS[@]}" "${AUTO_INCLUDE_FLAGS[@]}" "${BIB_COMPILE_FLAGS[@]}" \
        -MMD -MP -MF "$dep" -MT "$obj" \
        -c "$src" -o "$obj"
    else
      echo "  [CXX] $rel"
      g++ "${COMMON_FLAGS[@]}" "${AUTO_INCLUDE_FLAGS[@]}" "${BIB_COMPILE_FLAGS[@]}" \
        -MMD -MP -MF "$dep" -MT "$obj" \
        -c "$src" -o "$obj"
    fi
  else
    echo "  [SKIP] $rel"
  fi
  OBJECTS+=("$obj")
done

LINKER="gcc"
if [ "$HAS_CPP" = true ] || is_cpp_file "$MAIN_FILE"; then
  LINKER="g++"
fi

OUT_BIN="$BIN_DIR/$OUT_NAME"

NEED_LINK=false
if [ ! -f "$OUT_BIN" ]; then
  NEED_LINK=true
else
  for obj in "${OBJECTS[@]}"; do
    if [[ "$obj" -nt "$OUT_BIN" ]]; then
      NEED_LINK=true
      break
    fi
  done
fi

if [ "$NEED_LINK" = true ]; then
  echo "Linkando: $OUT_BIN"
  "$LINKER" "${OBJECTS[@]}" "${BIB_LINK_FLAGS[@]}" -o "$OUT_BIN"
else
  echo "Link: [SKIP] (binário atualizado)"
fi

echo "✓ Compilação concluída: $OUT_BIN"

#==============================================================================
# EXECUÇÃO
#==============================================================================
if [ "$RUN" = true ]; then 
  echo ""
  if [ "$NEED_INPUT" = true ]; then
    echo "=== Executando (modo interativo) ==="
    "$OUT_BIN"
  else
    # Cria in.txt e out.txt se não existirem
    touch "$ROOT/in.txt" "$ROOT/out.txt"

    echo "=== Executando (input: in.txt, output: out.txt) ==="
    if ! "$OUT_BIN" < "$ROOT/in.txt" > "$ROOT/out.txt"; then
      echo "Erro: Falha na execução." >&2
      exit 1
    fi
    echo "✓ Executado com sucesso"
    echo "  Saída salva em: $ROOT/out.txt"
  fi
fi