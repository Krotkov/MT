//
// Created by kranya on 22.12.2019.
//

#include <bits/stdc++.h>
#include "pascalParser.h"
#include "../Tree.h"

int main() {
    pascalParser parser;
    std::string str;
    getline(std::cin, str);
    pascalLexer lexer;
    lexer.updateInput(str);
    std::vector<Token> vect;
    while (lexer.curToken() != END) {
        vect.push_back(lexer.curToken());
        lexer.nextToken();
    }
    parser.updateInput(str);
    Tree tree = parser.parse();
    std::set<int> se;
    printTree(tree, 0, se);
    return 0;
}