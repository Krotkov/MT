cmake_minimum_required(VERSION 3.7)
project (ParserGenerator)

set(CMAKE_CXX_STANDARD 14)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(MyParser generatorGrammar.y ${PROJECT_SOURCE_DIR}/generatorGrammar.tab.cpp)
FLEX_TARGET(MyScanner generatorGrammar.l ${PROJECT_SOURCE_DIR}/generatorGrammar.lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(grammarGeneratorParser
        main.cpp
        Generator.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS})

add_executable(testLexer test.cpp gen/inputLexer.cpp)