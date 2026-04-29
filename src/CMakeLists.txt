# Coleta todos os .cpp do diretório src (recursivamente)
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

# Separa os fontes da biblioteca (exclui main.cpp)
set(SOURCE_LIB_SOURCES)
foreach(_src IN LISTS ALL_SOURCES)
    get_filename_component(_name ${_src} NAME)
    if(NOT _name STREQUAL "main.cpp")
        list(APPEND SOURCE_LIB_SOURCES ${_src})
    endif()
endforeach()

add_library(Source_Lib STATIC ${SOURCE_LIB_SOURCES})

target_include_directories(Source_Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Executável principal apenas com main.cpp
add_executable(SprintManager ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(SprintManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SprintManager
    PRIVATE Source_Lib
    PRIVATE SQLiteCpp_lib
    PRIVATE sqlite3_lib
    PRIVATE ${CMAKE_DL_LIBS}
)