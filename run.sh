#!/bin/bash
# filepath: /home/otaviano/Documentos/estrutura_dados/run.sh
set -euo pipefail

shopt -s nullglob

#==============================================================================
# VARIÁVEIS GLOBAIS
#==============================================================================
FILE=""
BIB_FILE=""
NEED_INPUT=false
RUN=true
ROOT=""
DIRNAME=""
FILENAME=""
BIB=""

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

show_help() {
  cat << EOF
Uso: $0 [opções]

Opções:
  -f FILE       Arquivo .c/.cpp a ser compilado (obrigatório)
  -b FILE       Arquivo com flags/arquivos extras (padrão: <root>/bib.txt)
  -i            Executa interativamente (aguarda input do usuário)
  -d            Compila sem executar
                Sem -i: redireciona in.txt para o programa e saída para out.txt
  -h            Mostra esta ajuda

Exemplos:
  $0 -f stack/notacao_polonesa.c
  $0 -f stack/notacao_polonesa.c -i
  $0 -f sprint/main.cpp
  $0 -f sprint/main.cpp -b bib.txt
EOF
  exit 0
}

#==============================================================================
# PROCESSAMENTO DE ARGUMENTOS
#==============================================================================
while getopts ":f:ib:hd" opt; do
  case $opt in
    f) 
      FILE="$OPTARG"
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
    d)
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
if [ -z "$FILE" ]; then
  echo "Erro: -f <file.c/.cpp> é obrigatório." >&2
  show_help
fi

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FILE="$(resolve_path "$FILE")"
DIRNAME="$(dirname "$FILE")"
BASEFILE="$(basename "$FILE")"
FILENAME="${BASEFILE%.*}"
EXT="${BASEFILE##*.}"
EXT_LC="${EXT,,}"

if [ ! -f "$FILE" ]; then
  echo "Erro: Arquivo '$FILE' não encontrado." >&2
  exit 1
fi

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
  BIB=""
  while IFS= read -r line; do
    # Ignora linhas vazias e comentários
    [[ -z "$line" || "$line" =~ ^[[:space:]]*# ]] && continue

    # Permite flags (ex: -lm, -lstdc++fs) e caminhos absolutos.
    if [[ "$line" == -* ]]; then
      BIB+=" $line"
    elif [[ "$line" == /* ]]; then
      BIB+=" $line"
    else
      BIB+=" $ROOT/$line"
    fi
  done < "$BIB_FILE"
fi

#==============================================================================
# COMPILAÇÃO
#==============================================================================
COMPILER=""
SOURCES=()

case "$EXT_LC" in
  c)
    COMPILER="gcc"
    SOURCES=("$DIRNAME"/*.c)
    ;;
  cpp|cc|cxx|c++)
    COMPILER="g++"
    SOURCES=("$DIRNAME"/*.cpp "$DIRNAME"/*.cc "$DIRNAME"/*.cxx "$DIRNAME"/*.c++)
    ;;
  *)
    echo "Erro: extensão '.$EXT' não suportada (use .c ou .cpp)." >&2
    exit 1
    ;;
esac

if [ "${#SOURCES[@]}" -eq 0 ]; then
  echo "Erro: nenhum arquivo fonte encontrado em '$DIRNAME'." >&2
  exit 1
fi

echo "Compilando $FILE..."
if ! "$COMPILER" -g "${SOURCES[@]}" $BIB -o "$DIRNAME/bin/Debug/$FILENAME"; then
  echo "Erro: Falha na compilação." >&2
  exit 1
fi

echo "✓ Compilação concluída: $DIRNAME/$FILENAME"

#==============================================================================
# EXECUÇÃO
#==============================================================================
if [ "$RUN" = true ]; then 
  echo ""
  if [ "$NEED_INPUT" = true ]; then
    echo "=== Executando (modo interativo) ==="
    "$DIRNAME/bin/Debug/$FILENAME"
  else
    echo "=== Executando (input: in.txt, output: out.txt) ==="
    if ! "$DIRNAME/bin/Debug/$FILENAME" < "$ROOT/in.txt" > "$ROOT/out.txt"; then
      echo "Erro: Falha na execução." >&2
      exit 1
    fi
    echo "✓ Executado com sucesso"
    echo "  Saída salva em: $ROOT/out.txt"
  fi
fi