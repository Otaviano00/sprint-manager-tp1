file(GLOB_RECURSE SPRINTMANAGER_SOURCES "*.cpp")
list(REMOVE_ITEM SPRINTMANAGER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

add_library(SprintManagerCore STATIC ${SPRINTMANAGER_SOURCES})
target_include_directories(SprintManagerCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SprintManagerCore
    PUBLIC SQLiteCpp_lib
    PUBLIC sqlite3_lib
    PUBLIC ${CMAKE_DL_LIBS}
)

add_executable(SprintManager main.cpp)
target_link_libraries(SprintManager PRIVATE SprintManagerCore pthread)