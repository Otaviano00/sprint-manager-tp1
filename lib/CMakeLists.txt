# --- 1. COMPILAR O SQLITE3 ---
add_library(sqlite3_lib STATIC 
    sqlite3/sqlite3.c
)
target_include_directories(sqlite3_lib PUBLIC sqlite3)

# --- 2. COMPILAR O SQLITECPP ---
file(GLOB SQLITECPP_SOURCES "SQLiteCpp/src/*.cpp")

add_library(SQLiteCpp_lib STATIC 
    ${SQLITECPP_SOURCES}
)
target_include_directories(SQLiteCpp_lib PUBLIC SQLiteCpp/include)

# O SQLiteCpp precisa saber onde está o sqlite3.h
target_link_libraries(SQLiteCpp_lib PUBLIC sqlite3_lib)
