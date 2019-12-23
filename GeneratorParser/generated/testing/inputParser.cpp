#include <bits/stdc++.h>
#include "inputParser.h"

void inputParser::updateInput(std::string& input) {
    lexer.updateInput(input);
}
void inputParser::parse() {
    lexer.nextToken();
    E();
}
int inputParser::E() {
    if (lexer.curToken() == LBR) {
        auto val0 = T();
        auto val1 = E2();
       
        int retVal = 0;
       return retVal;
    } else if (lexer.curToken() == NUM) {
        auto val0 = T();
        auto val1 = E2();
       
        int retVal = 0;
       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
int inputParser::E2() {
    if (lexer.curToken() == PLUS) {
        lexer.nextToken();
        auto val0 = lexer.tokenString();
        auto val1 = T();
        auto val2 = E2();
       
        int retVal = 0;
       return retVal;
    } else if (lexer.curToken() == END || lexer.curToken() == RBR || false) {
        lexer.nextToken();
        auto val0 = lexer.tokenString();
       
        int retVal = 0;
       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
int inputParser::F() {
    if (lexer.curToken() == LBR) {
        lexer.nextToken();
        auto val0 = lexer.tokenString();
        auto val1 = E();
        lexer.nextToken();
        auto val2 = lexer.tokenString();
       
        int retVal = 0;
       return retVal;
    } else if (lexer.curToken() == NUM) {
        lexer.nextToken();
        auto val0 = lexer.tokenString();
       
        int retVal = 0;
       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
int inputParser::T() {
    if (lexer.curToken() == NUM) {
        auto val0 = F();
        auto val1 = T2();
       
        int retVal = 0;
       return retVal;
    } else if (lexer.curToken() == LBR) {
        auto val0 = F();
        auto val1 = T2();
       
        int retVal = 0;
       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
int inputParser::T2() {
    if (lexer.curToken() == MUL) {
        lexer.nextToken();
        auto val0 = lexer.tokenString();
        auto val1 = F();
        auto val2 = T2();
       
        int retVal = 0;
       return retVal;
    } else if (lexer.curToken() == RBR || lexer.curToken() == END || lexer.curToken() == PLUS || false) {
        lexer.nextToken();
        auto val0 = lexer.tokenString();
       
        int retVal = 0;
       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
