cmake_minimum_required(VERSION 3.7)
project (LexerGenerator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(parseLexer)

add_library(generateLexer LexerGenerator.cpp LexerGenerator.h)

target_link_libraries(generateLexer parseLexer)