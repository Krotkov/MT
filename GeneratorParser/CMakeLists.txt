cmake_minimum_required(VERSION 3.7)
project (ParserGenerator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Lexer)

add_executable(generate main.cpp)

target_link_libraries(generate generateLexer)

add_executable (test generated/testing/main.cpp generated/testing/inputLexer.cpp)