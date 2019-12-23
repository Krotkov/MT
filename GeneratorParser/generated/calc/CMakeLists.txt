cmake_minimum_required(VERSION 3.7)
project (test)

set(CMAKE_CXX_STANDARD 14)

add_executable(testCalc main.cpp inputParser.cpp inputLexer.cpp ../Tree.cpp)

