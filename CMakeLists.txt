cmake_minimum_required(VERSION 3.10)
project(sprint-manager-tp1)

# Define o padrão do C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# 1. Identifica todos os arquivos .cpp recursivamente
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 2. Identifica os diretórios de cabeçalhos (.hpp) para que você não precise
file(GLOB_RECURSE HEADERS "src/*.hpp")
get_filename_component(INCLUDE_DIRS "src" ABSOLUTE)

# 3. Define o executável e inclui os arquivos encontrados
add_executable(main ${SOURCES})

# 4. Diz ao compilador onde procurar os .hpp
target_include_directories(main PUBLIC src)