cmake_minimum_required(VERSION 3.7)
project (ParserLexer)

set(CMAKE_CXX_STANDARD 14)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser ${PROJECT_SOURCE_DIR}/generatorLexer.y ${PROJECT_SOURCE_DIR}/generatorLexer.tab.cpp)
FLEX_TARGET(MyScanner ${PROJECT_SOURCE_DIR}/generatorLexer.l ${PROJECT_SOURCE_DIR}/generatorLexer.lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_library(parseLexer
        parseLexer.h
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})
