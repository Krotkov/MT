cmake_minimum_required(VERSION 3.7)
project (ParserGenerator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Lexer)
add_subdirectory(Parser)
add_subdirectory(generated)

add_executable(generate main.cpp)

target_link_libraries(generate generateLexer generateParser)

