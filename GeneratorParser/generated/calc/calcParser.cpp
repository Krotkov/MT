#include <bits/stdc++.h>
#include "calcParser.h"

void calcParser::updateInput(std::string& input) {
    lexer.updateInput(input);
}
Tree calcParser::parse() {
    lexer.nextToken();
    return E();
}
Tree calcParser::E() {
    if (lexer.curToken() == MINUS) {
        if (lexer.curToken() != MINUS) throw std::runtime_error("bad_token");
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
       throw std::runtime_error("bad token");
    }
}
Tree calcParser::E2() {
    if (lexer.curToken() == PLUS) {
        if (lexer.curToken() != PLUS) throw std::runtime_error("bad_token");
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
        if (lexer.curToken() != MINUS) throw std::runtime_error("bad_token");
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
       throw std::runtime_error("bad token");
    }
}
Tree calcParser::F() {
    if (lexer.curToken() == LBR) {
        if (lexer.curToken() != LBR) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = E();
        if (lexer.curToken() != RBR) throw std::runtime_error("bad_token");
        auto val3 = lexer.tokenString();
        lexer.nextToken();
       std::vector<Tree> children;
children.emplace_back("(");
children.emplace_back(val2);
children.emplace_back(")");
auto retVal = Tree("F", children);

       return retVal;
    } else if (lexer.curToken() == NUM) {
        if (lexer.curToken() != NUM) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
       std::vector<Tree> children;
children.emplace_back(val1);
auto retVal = Tree("F", children);

       return retVal;
    } else {
       throw std::runtime_error("bad token");
    }
}
Tree calcParser::T() {
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
       throw std::runtime_error("bad token");
    }
}
Tree calcParser::T2() {
    if (lexer.curToken() == MUL) {
        if (lexer.curToken() != MUL) throw std::runtime_error("bad_token");
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
        if (lexer.curToken() != DIV) throw std::runtime_error("bad_token");
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
       throw std::runtime_error("bad token");
    }
}
