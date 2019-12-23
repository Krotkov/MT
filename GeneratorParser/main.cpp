//
// Created by kranya on 15.12.2019.
//

#include <bits/stdc++.h>
#include "Lexer/LexerGenerator.h"
#include "Parser/ParserGenerator.h"

using namespace std;


int main() {
    LexerGenerator::generate("/home/kranya/MT/GeneratorParser/generated/calc", "input");
    ParserGenerator::generate("/home/kranya/MT/GeneratorParser/generated/calc", "input");
    return 0;
}