#include <bits/stdc++.h>
#include "pascalParser.h"

void pascalParser::updateInput(std::string &input) {
    lexer.updateInput(input);
}

Tree pascalParser::parse() {
    lexer.nextToken();
    return S();
}

Tree pascalParser::A() {
    if (lexer.curToken() == NAME) {
        auto val1 = VS();
        if (lexer.curToken() != COLON) throw std::runtime_error("bad_token");
        auto val2 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != TYPE) throw std::runtime_error("bad_token");
        auto val3 = lexer.tokenString();
        lexer.nextToken();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        children.emplace_back(val3);
        auto retVal = Tree("A", children);

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

Tree pascalParser::AS() {
    if (lexer.curToken() == NAME) {
        auto val1 = A();
        auto val2 = AS2();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        auto retVal = Tree("AS", children);

        return retVal;
    } else if (lexer.curToken() == RBR || false) {
        auto retVal = Tree("AS");

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

Tree pascalParser::AS2() {
    if (lexer.curToken() == SEMICOLON) {
        if (lexer.curToken() != SEMICOLON) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = A();
        auto val3 = AS2();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        children.emplace_back(val3);
        auto retVal = Tree("AS2", children);

        return retVal;
    } else if (lexer.curToken() == RBR || false) {
        auto retVal = Tree("AS2");

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

Tree pascalParser::S() {
    if (lexer.curToken() == PROCEDURE) {
        if (lexer.curToken() != PROCEDURE) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
        auto val2 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != LBR) throw std::runtime_error("bad_token");
        auto val3 = lexer.tokenString();
        lexer.nextToken();
        auto val4 = AS();
        if (lexer.curToken() != RBR) throw std::runtime_error("bad_token");
        auto val5 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != SEMICOLON) throw std::runtime_error("bad_token");
        auto val6 = lexer.tokenString();
        lexer.nextToken();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        children.emplace_back(val3);
        children.emplace_back(val4);
        children.emplace_back(val5);
        children.emplace_back(val6);
        auto retVal = Tree("S", children);

        return retVal;
    } else if (lexer.curToken() == FUNCTION) {
        if (lexer.curToken() != FUNCTION) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
        auto val2 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != LBR) throw std::runtime_error("bad_token");
        auto val3 = lexer.tokenString();
        lexer.nextToken();
        auto val4 = AS();
        if (lexer.curToken() != RBR) throw std::runtime_error("bad_token");
        auto val5 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != COLON) throw std::runtime_error("bad_token");
        auto val6 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != TYPE) throw std::runtime_error("bad_token");
        auto val7 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != SEMICOLON) throw std::runtime_error("bad_token");
        auto val8 = lexer.tokenString();
        lexer.nextToken();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        children.emplace_back(val3);
        children.emplace_back(val4);
        children.emplace_back(val5);
        children.emplace_back(val6);
        children.emplace_back(val7);
        children.emplace_back(val8);
        auto retVal = Tree("S", children);

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

Tree pascalParser::VS() {
    if (lexer.curToken() == NAME) {
        if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = VS2();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        auto retVal = Tree("VS", children);

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

Tree pascalParser::VS2() {
    if (lexer.curToken() == COMMA) {
        if (lexer.curToken() != COMMA) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
        auto val2 = lexer.tokenString();
        lexer.nextToken();
        auto val3 = VS2();
        std::vector<Tree> children;
        children.emplace_back(val1);
        children.emplace_back(val2);
        children.emplace_back(val3);
        auto retVal = Tree("VS2", children);

        return retVal;
    } else if (lexer.curToken() == COLON || false) {
        auto retVal = Tree("VS2");

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}
