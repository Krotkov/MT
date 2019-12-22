//
// Created by kranya on 22.12.2019.
//

#include <iostream>
#include "gen/inputLexer.h"

int main() {
    std::string str;
    getline (std::cin, str);
    inputLexer lexer;
    lexer.updateInput(str);
    lexer.nextToken();
    std::vector<Token> tokens;
    while (lexer.curToken() != END) {
        tokens.push_back(lexer.curToken());
        lexer.nextToken();
    }
    return 0;
}
