\page "Build e Run"

### Requisitos:
- `bash`
- `gcc` e/ou `g++` 

---

# Terminal

## Rodar (Release)

Sem flags, o script procura automaticamente por `src/**/main.(c|cpp|cc|cxx|c++)`.

```shell
./run.sh
```

O executável gerado fica em `bin/Release/main` (ou com o mesmo nome do arquivo principal, sem extensão).

## Escolher um main específico

Passe o caminho do arquivo principal via `-m`:

```shell
./run.sh -m src/main.cpp
```

## Debug

Compilar em Debug e executar:

```shell
./run.sh -g
```

Compilar em Debug sem executar:

```shell
./run.sh -d
```

O executável gerado fica em `bin/Debug/main`.

## Input/Output

- Com `-i`: execução interativa (stdin do terminal).
- Sem `-i`: o programa lê de `in.txt` e grava em `out.txt` na raiz do projeto.

```shell
./run.sh -i
```

## Ajuda

```shell
./run.sh -h
```

---

# VSCode

## Rodar (Release)

- `Ctrl+Shift+P` -> **Tasks: Run Task** -> `run_c`

## Rodar (Debug)

- Aba **Run and Debug** -> configuração **C/C++: run.sh build and debug active file**
  - Isso chama a task `run_c_debug` e debuga `bin/Debug/main`.
