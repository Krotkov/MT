cmake_minimum_required(VERSION 3.7)

project(FunctionalParser)

set(CMAKE_CXX_STANDARD 14)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser grammar.y ${PROJECT_SOURCE_DIR}/grammar.tab.cpp)
FLEX_TARGET(MyScanner grammar.l ${PROJECT_SOURCE_DIR}/grammar.lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(pascalParser
        main.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})