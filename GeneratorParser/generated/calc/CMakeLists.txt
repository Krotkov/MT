cmake_minimum_required(VERSION 3.7)
project (calc)

set(CMAKE_CXX_STANDARD 14)

add_executable(testCalc main.cpp calcParser.cpp calcLexer.cpp ../Tree.cpp)

