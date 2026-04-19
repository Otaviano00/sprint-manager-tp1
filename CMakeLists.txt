cmake_minimum_required(VERSION 3.10)
project(sprint-manager-tp1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. COMPILAR O SQLITE3 (C puro) ---
add_library(sqlite3_lib STATIC 
    deps/sqlite3/sqlite3.c
)
target_include_directories(sqlite3_lib PUBLIC deps/sqlite3)

# --- 2. COMPILAR O SQLITECPP ---
file(GLOB SQLITECPP_SOURCES "deps/SQLiteCpp/src/*.cpp")

add_library(SQLiteCpp_lib STATIC 
    ${SQLITECPP_SOURCES}
)
target_include_directories(SQLiteCpp_lib PUBLIC deps/SQLiteCpp/include)

# O SQLiteCpp precisa saber onde está o sqlite3.h
target_link_libraries(SQLiteCpp_lib PUBLIC sqlite3_lib)

# --- 3. COMPILAR O PROJETO ---
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(main ${SOURCES})

target_include_directories(main PRIVATE src)

target_link_libraries(main 
    PRIVATE SQLiteCpp_lib 
    PRIVATE sqlite3_lib
    PRIVATE ${CMAKE_DL_LIBS}
)
