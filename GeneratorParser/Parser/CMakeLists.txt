cmake_minimum_required(VERSION 3.7)
project (ParserGenerator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(parseParser)

add_library(generateParser ParserGenerator.cpp ParserGenerator.h)

target_link_libraries(generateParser parseParser)
