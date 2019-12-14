//
// Created by kranya on 09.12.2019.
//

#ifndef MT_PARSER_H
#define MT_PARSER_H

#include "Lexer.h"
#include "Tree.h"

class Parser {
    Lexer lexer;
    Tree S();
    Tree F();
    Tree P();
    Tree AS();
    Tree AS2();
    Tree A();
    Tree VS();
    Tree VS2();

public:
    Tree parse(std::string& a);

    Parser();
};


#endif //MT_PARSER_H
