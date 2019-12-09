cmake_minimum_required(VERSION 3.15)
project(MT)

set(CMAKE_CXX_STANDARD 17)

add_executable(parser main.cpp Lexer.cpp Tree.cpp Parser.cpp)

add_executable(parser_testing test.cpp gtest/gtest-all.cc
        gtest/gtest.h
        gtest/gtest_main.cc Lexer.h Lexer.cpp Tree.h Tree.cpp Parser.h Parser.cpp)

target_link_libraries(parser_testing -lgmp -lgmpxx -lpthread)
