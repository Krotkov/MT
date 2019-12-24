cmake_minimum_required(VERSION 3.7)
project (pascal)

set(CMAKE_CXX_STANDARD 14)

add_executable(testPascal main.cpp pascalParser.cpp pascalLexer.cpp ../Tree.cpp)

