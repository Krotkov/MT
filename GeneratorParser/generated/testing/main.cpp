//
// Created by kranya on 22.12.2019.
//

#include <bits/stdc++.h>
#include "inputLexer.h"

int main() {
    std::string str;
    getline(std::cin, str);
    inputLexer lexer;
    lexer.nextToken();
    std::vector<Token> vect;
    while (lexer.curToken() != END) {
        vect.push_back(lexer.curToken());
        lexer.nextToken();
    }
    return 0;
}