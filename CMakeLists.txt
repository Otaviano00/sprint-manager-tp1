cmake_minimum_required(VERSION 3.10)
project(sprint-manager-tp1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adiciona os subdiretórios para o CMake
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

