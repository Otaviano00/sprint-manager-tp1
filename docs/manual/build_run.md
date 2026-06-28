\page "Build e Run"

# Build e Run

### Requisitos:

- `cmake`
- `g++`
- `mingw` (no Windows)

---

# Terminal

## Compilação (Sem CodeBlocks)

Para compilar o projeto diretamente pelo terminal sem depender do CodeBlocks, utilize os comandos abaixo de acordo com o seu sistema operacional.

Estes comandos geram a base do projeto para debug na pasta `build`, criam automaticamente o arquivo de projeto do CodeBlocks, compilam as classes e linkam os objetos necessários.

### Linux:

```sh
cmake -B build -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" && cmake --build build
```

### Windows:

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - MinGW Makefiles" && cmake --build build
```

## Execução

Após a compilação, o executável principal do projeto estará pronto. Para rodá-lo, basta executar o binário contido no seguinte caminho:

### Linux:

```sh
./build/src/SprintManager
```

### Windows:

```bash
build\src\SprintManager.exe
```

## Tests

Para executar os testes, veja \ref "Testes" [Testes](tests.md)
