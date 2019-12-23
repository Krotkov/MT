cmake_minimum_required(VERSION 3.7)
project (ParserParser)

set(CMAKE_CXX_STANDARD 14)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser generatorParser.y ${PROJECT_SOURCE_DIR}/generatorParser.tab.cpp)
FLEX_TARGET(MyScanner generatorParser.l ${PROJECT_SOURCE_DIR}/generatorParser.lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_library(parseParser parseParser.h ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})