include(CTest)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "TU*.cpp")

# Cria a biblioteca base como INTERFACE (para o UnitBaseTest.hpp)
add_library(TestsCore INTERFACE)
target_include_directories(TestsCore INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

foreach(test_source IN LISTS TEST_SOURCES)
    get_filename_component(test_name ${test_source} NAME_WE)
    
    add_executable(${test_name} ${test_source})
    
    target_include_directories(${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    
    target_link_libraries(${test_name} 
        PRIVATE SprintManagerCore
        PRIVATE TestsCore
    )
    
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()