import os
import subprocess
import argparse
import sys

def setup_files(use_terminal):
    if not use_terminal:
        for file in ['in.txt', 'out.txt']:
            if not os.path.exists(file):
                with open(file, 'w') as f:
                    pass
                print(f"[*] Criado: {file}")

def run_command(command, debug=False):
    if debug:
        print(f"[DEBUG] Executando: {' '.join(command)}")
    
    try:
        # shell=True é necessário no Windows para alguns comandos de sistema
        result = subprocess.run(command, check=True)
        return True
    except subprocess.CalledProcessError as e:
        print(f"[ERRO] Falha ao executar comando: {e}")
        return False

def main():
    parser = argparse.ArgumentParser(description="Build e Execution Helper para Projetos C++ (CMake)")
    parser.add_argument("-d", "--debug", action="store_true", help="Mostra os comandos detalhados")
    parser.add_argument("-b", "--build-only", action="store_true", help="Apenas compila o projeto sem rodar")
    parser.add_argument("-i", "--interactive", action="store_true", help="Usa o terminal para input/output em vez de arquivos .txt")
    
    args = parser.parse_args()

    # 1. Configuração do CMake (Cria a pasta build se não existir)
    if not os.path.exists("build"):
        print("[*] Configurando CMake...")
        run_command(["cmake", "-B", "build"], args.debug)

    # 2. Compilação
    print("[*] Compilando...")
    if not run_command(["cmake", "--build", "build"], args.debug):
        sys.exit(1)

    if args.build_only:
        print("[*] Build concluído com sucesso.")
        return

    # 3. Preparação de arquivos
    setup_files(args.interactive)

    # 4. Execução
    # Nota: O nome do executável deve ser o mesmo definido no CMakeLists.txt (ex: main)
    executable = os.path.join("build", "main")
    if os.name == 'nt' and not os.path.exists(executable):
        executable = os.path.join("build", "Debug", "main.exe")

    print(f"[*] Rodando {executable}...")
    
    try:
        if args.interactive:
            subprocess.run([executable], check=True)
        else:
            with open("in.txt", "r") as fin, open("out.txt", "w") as fout:
                subprocess.run([executable], stdin=fin, stdout=fout, check=True)
            print("[*] Execução finalizada. Resultados em out.txt")
    except Exception as e:
        print(f"[ERRO] Erro na execução: {e}")

if __name__ == "__main__":
    main()