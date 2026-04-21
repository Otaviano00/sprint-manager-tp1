file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(SprintManager ${SOURCES})

target_include_directories(SprintManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(SprintManager 
    PRIVATE SQLiteCpp_lib 
    PRIVATE sqlite3_lib
    PRIVATE ${CMAKE_DL_LIBS}
)