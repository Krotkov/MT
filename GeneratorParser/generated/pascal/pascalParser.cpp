#include <bits/stdc++.h>
#include "pascalParser.h"

void pascalParser::updateInput(std::string& input) {
    lexer.updateInput(input);
}
Tree pascalParser::parse() {
    lexer.nextToken();
    return S({});
}
Tree pascalParser::A(std::string type) {
    if (lexer.curToken() == NAME) {
               auto val1 = VS(type);
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
Tree pascalParser::AS(std::string type) {
    if (lexer.curToken() == NAME) {
               auto val1 = A(type);
        auto val2 = AS2(type);

std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("AS", children);

       return retVal;
    } else if (lexer.curToken() == RBR || false) {
       auto retVal  = Tree("AS");

       return retVal;
    } else {
       throw std::runtime_error("bad token");
    }
}
Tree pascalParser::AS2(std::string type) {
    if (lexer.curToken() == SEMICOLON) {
       if (lexer.curToken() != SEMICOLON) throw std::runtime_error("bad_token");
auto val1 = lexer.tokenString();
lexer.nextToken();
        auto val2 = A(type);
        auto val3 = AS2(type);

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
Tree pascalParser::S(std::string type) {
    if (lexer.curToken() == PROCEDURE) {
       if (lexer.curToken() != PROCEDURE) throw std::runtime_error("bad_token");
auto val1 = lexer.tokenString();
lexer.nextToken();
if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
auto val2 = lexer.tokenString();
lexer.nextToken();
        auto val3 = SIGNAT(type);
if (lexer.curToken() != SEMICOLON) throw std::runtime_error("bad_token");
auto val4 = lexer.tokenString();
lexer.nextToken();

std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
children.emplace_back(val3);
children.emplace_back(val4);
auto retVal = Tree("S", children);

       return retVal;
    } else if (lexer.curToken() == FUNCTION) {
       if (lexer.curToken() != FUNCTION) throw std::runtime_error("bad_token");
auto val1 = lexer.tokenString();
lexer.nextToken();
if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
auto val2 = lexer.tokenString();
lexer.nextToken();
        auto val3 = SIGNAT(type);
if (lexer.curToken() != COLON) throw std::runtime_error("bad_token");
auto val4 = lexer.tokenString();
lexer.nextToken();
if (lexer.curToken() != TYPE) throw std::runtime_error("bad_token");
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
    } else {
       throw std::runtime_error("bad token");
    }
}
Tree pascalParser::SIGNAT(std::string type) {
    if (lexer.curToken() == LBR) {
       if (lexer.curToken() != LBR) throw std::runtime_error("bad_token");
auto val1 = lexer.tokenString();
lexer.nextToken();
        auto val2 = AS(type);
if (lexer.curToken() != RBR) throw std::runtime_error("bad_token");
auto val3 = lexer.tokenString();
lexer.nextToken();

std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
children.emplace_back(val3);
auto retVal = Tree("SIGNAT", children);

       return retVal;
    } else if (lexer.curToken() == SEMICOLON || lexer.curToken() == COLON || false) {
       auto retVal = Tree("SIGNAT");

       return retVal;
    } else {
       throw std::runtime_error("bad token");
    }
}
Tree pascalParser::VS(std::string type) {
    if (lexer.curToken() == NAME) {
       if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
auto val1 = lexer.tokenString();
lexer.nextToken();
        auto val2 = VS2(type);

std::vector<Tree> children;
children.emplace_back(val1);
children.emplace_back(val2);
auto retVal = Tree("VS", children);

       return retVal;
    } else {
       throw std::runtime_error("bad token");
    }
}
Tree pascalParser::VS2(std::string type) {
    if (lexer.curToken() == COMMA) {
       if (lexer.curToken() != COMMA) throw std::runtime_error("bad_token");
auto val1 = lexer.tokenString();
lexer.nextToken();
if (lexer.curToken() != NAME) throw std::runtime_error("bad_token");
auto val2 = lexer.tokenString();
lexer.nextToken();
        auto val3 = VS2(type);

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
