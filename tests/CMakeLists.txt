# CMake para testes unitários
file(GLOB_RECURSE TEST_SOURCES "dominios/*.cpp")
add_executable(test_executable ${TEST_SOURCES})

# Linkar contra a biblioteca de origem e dependências necessárias
target_link_libraries(test_executable PRIVATE
    Source_Lib
)

add_test(RunUnitTests test_executable)