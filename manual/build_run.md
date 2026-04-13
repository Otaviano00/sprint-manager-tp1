\page "Build e Run"

### Requisitos:
- `python`
- `cmake`
- `g++`
- `mingw` (no Windows)

---

# Terminal

## Rodar (Release)

O script `run.py` compila e executa o projeto.

```shell
python run.py
```

O executável gerado fica em `build/main.exe`.

## Debug

Apenas compilar o projeto (sem executar):

```shell
python run.py -b
```

## Input/Output

- Com `-i`: execução interativa (stdin do terminal).
- Sem `-i`: o programa lê de `in.txt` e grava em `out.txt` na raiz do projeto.

```shell
python run.py -i
```

## Ajuda

```shell
python run.py -h
```

---

# VSCode

## Rodar (Release)

- `Ctrl+Shift+P` -> **Tasks: Run Task** -> `run_c_full`

## Rodar (Debug)

- Adicione o breakpoint -> aperte F5
  - Isso chama a task `run_c_debug` e debuga `build/main.exe`.
