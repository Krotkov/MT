#include <bits/stdc++.h>
#include "inputParser.h"

void inputParser::updateInput(std::string& input) {
    lexer.updateInput(input);
}
Tree inputParser::parse() {
    lexer.nextToken();
    return E();
}
Tree inputParser::E() {
    if (lexer.curToken() == MINUS) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = E();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("E", children);

       return retVal;
    } else if (lexer.curToken() == LBR) {
        auto val1 = T();
        auto val2 = E2();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("E", children);

       return retVal;
    } else if (lexer.curToken() == NUM) {
        auto val1 = T();
        auto val2 = E2();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("E", children);

       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
Tree inputParser::E2() {
    if (lexer.curToken() == PLUS) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = T();
        auto val3 = E2();
       std::vector<Tree> children;
children.emplace_back("+");
children.emplace_back(val2);
children.emplace_back(val3);
auto retVal = Tree("E2", children);

       return retVal;
    } else if (lexer.curToken() == MINUS) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = T();
        auto val3 = E2();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
children.emplace_back(val3);
auto retVal = Tree("E2", children);

       return retVal;
    } else if (lexer.curToken() == END || lexer.curToken() == RBR || false) {
       auto retVal = Tree("E2");

       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
Tree inputParser::F() {
    if (lexer.curToken() == LBR) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = E();
        auto val3 = lexer.tokenString();
        lexer.nextToken();
       std::vector<Tree> children;
children.emplace_back("(");
children.emplace_back(val2);
children.emplace_back(")");
auto retVal = Tree("F", children);

       return retVal;
    } else if (lexer.curToken() == NUM) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
       std::vector<Tree> children;
children.emplace_back(val1);
auto retVal = Tree("F", children);

       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
Tree inputParser::T() {
    if (lexer.curToken() == NUM) {
        auto val1 = F();
        auto val2 = T2();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("T", children);

       return retVal;
    } else if (lexer.curToken() == LBR) {
        auto val1 = F();
        auto val2 = T2();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("T", children);

       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
Tree inputParser::T2() {
    if (lexer.curToken() == MUL) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = F();
        auto val3 = T2();
       std::vector<Tree> children;
children.emplace_back("*");
children.emplace_back(val2);
children.emplace_back(val3);
auto retVal = Tree("T2", children);

       return retVal;
    } else if (lexer.curToken() == DIV) {
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = F();
        auto val3 = T2();
       std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
children.emplace_back(val3);
auto retVal = Tree("T2", children);

       return retVal;
    } else if (lexer.curToken() == RBR || lexer.curToken() == MINUS || lexer.curToken() == END || lexer.curToken() == PLUS || false) {
       auto retVal = Tree("T2");

       return retVal;
    } else {
       throw new std::runtime_error("bad token");
    }
}
