//
// Created by kranya on 09.12.2019.
//

#include <iostream>
#include <vector>
#include <set>
#include "Parser.h"

int main () {
    std::string str;
    getline(std::cin, str);
    Lexer lexer(str);
    std::vector <Token> vect;
    while (lexer.curToken() != Token::END) {
        vect.push_back(lexer.curToken());
        lexer.nextToken();
    }
    Tree ans = Parser().parse(str);
    std::set<int> se;
    printTree(ans, 0, se);
    return 0;
}