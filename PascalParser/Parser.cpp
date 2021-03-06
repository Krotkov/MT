//
// Created by kranya on 09.12.2019.
//

#include <stdexcept>
#include "Parser.h"

Tree Parser::S() {
    Tree child;
    std::vector<Tree> children;
    switch (lexer.curToken()) {
        case (Token::FUNCTION):
            child = F();
            if (lexer.curToken() != Token::END) {
                throw std::runtime_error("S");
            }
            children.emplace_back(child);
            return Tree("S", children);
        case (Token::PROCEDURE):
            child = P();
            if (lexer.curToken() != Token::END) {
                throw std::runtime_error("S");
            }
            children.emplace_back(child);
            return Tree("S", children);
        case (Token::END):
            return Tree("S");
        default:
            throw std::runtime_error("S");
    }
}

Tree Parser::F() {
    Tree vars;
    Tree type;
    std::vector<Tree> children;
    std::string funcName;
    switch (lexer.curToken()) {
        case (Token::FUNCTION):
            lexer.nextToken();
            if (lexer.curToken() != Token::NAME) {
                throw std::runtime_error("F");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::LBRACKET) {
                if (lexer.curToken() != Token::COLON) {
                    throw std::runtime_error("F");
                }
                lexer.nextToken();
                if (lexer.curToken() != Token::TYPE) {
                    throw std::runtime_error("F");
                }
                lexer.nextToken();
                if (lexer.curToken() != Token::SEMICOLON) {
                    throw std::runtime_error("F");
                }
                lexer.nextToken();
                children.emplace_back("function");
                children.emplace_back("<name>");
                children.emplace_back(":");
                children.emplace_back("<type>");
                children.emplace_back(";");
                return Tree("F", children);
            }
            lexer.nextToken();
            vars = AS();
            if (lexer.curToken() != Token::RBRACKET) {
                throw std::runtime_error("F");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::COLON) {
                throw std::runtime_error("F");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::TYPE) {
                throw std::runtime_error("F");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::SEMICOLON) {
                throw std::runtime_error("F");
            }
            lexer.nextToken();
            children.emplace_back("function");
            children.emplace_back("<name>");
            children.emplace_back("(");
            children.emplace_back(vars);
            children.emplace_back(")");
            children.emplace_back(":");
            children.emplace_back("<type>");
            children.emplace_back(";");
            return Tree("F", children);
        default:
            throw std::runtime_error("F");

    }
}

Tree Parser::P() {
    Tree vars;
    Tree type;
    std::vector<Tree> children;
    std::string procName;
    switch (lexer.curToken()) {
        case (Token::PROCEDURE):
            lexer.nextToken();
            if (lexer.curToken() != Token::NAME) {
                throw std::runtime_error("P");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::LBRACKET) {
                if (lexer.curToken() != Token::SEMICOLON) {
                    throw std::runtime_error("F");
                }
                lexer.nextToken();
                children.emplace_back("procedure");
                children.emplace_back("<name>");
                children.emplace_back(";");
                return Tree("F", children);
            }
            lexer.nextToken();
            vars = AS();
            if (lexer.curToken() != Token::RBRACKET) {
                throw std::runtime_error("P");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::SEMICOLON) {
                throw std::runtime_error("P");
            }
            lexer.nextToken();
            children.emplace_back("procedure");
            children.emplace_back("<name>");
            children.emplace_back("(");
            children.emplace_back(vars);
            children.emplace_back(")");
            children.emplace_back(";");
            return Tree("F", children);
        default:
            throw std::runtime_error("P");

    }
}

Tree Parser::AS() {
    std::vector<Tree> children;
    Tree child, child2;
    switch (lexer.curToken()) {
        case (Token::NAME):
            child = A();
            child2 = AS2();
            children.emplace_back(child);
            children.emplace_back(child2);
            return Tree("AS", children);
        case (Token::RBRACKET):
            return Tree("AS");
        default:
            throw std::runtime_error("AS");
    }
}

Tree Parser::AS2() {
    std::vector<Tree> children;
    Tree child, child2;
    switch (lexer.curToken()) {
        case (Token::SEMICOLON):
            lexer.nextToken();
            child = A();
            child2 = AS2();
            children.emplace_back(";");
            children.emplace_back(child);
            children.emplace_back(child2);
            return Tree("AS2", children);
        case (Token::RBRACKET):
            return Tree("AS2");
        default:
            throw std::runtime_error("AS2");
    }
}

Tree Parser::A() {
    Tree child;
    std::vector<Tree> children;
    switch (lexer.curToken()) {
        case (Token::NAME):
            child = VS();
            if (lexer.curToken() != Token::COLON) {
                throw std::runtime_error("A");
            }
            lexer.nextToken();
            if (lexer.curToken() != Token::TYPE) {
                throw std::runtime_error("A");
            }
            lexer.nextToken();
            children.emplace_back(child);
            children.emplace_back(":");
            children.emplace_back("<type>");
            return Tree("A", children);
        default:
            throw std::runtime_error("A");
    }
}

Tree Parser::VS() {
    std::vector<Tree> children;
    Tree child;
    if (lexer.curToken() != Token::NAME) {
        throw std::runtime_error("VS");
    }
    lexer.nextToken();
    child = VS2();
    children.emplace_back("<name>");
    children.emplace_back(child);
    return Tree("VS", children);
}

Tree Parser::VS2() {
    std::vector<Tree> children;
    Tree child;
    switch (lexer.curToken()) {
        case (Token::COMMA):
            lexer.nextToken();
            if (lexer.curToken() != Token::NAME) {
                throw std::runtime_error("VS2");
            }
            lexer.nextToken();
            child = VS2();
            children.emplace_back(",");
            children.emplace_back("<name>");
            children.emplace_back(child);
            return Tree("VS2", children);
        case (Token::COLON):
            return Tree("VS2");
        default:
            throw std::runtime_error("VS2");
    }
}

Tree Parser::parse(std::string &a) {
    lexer = Lexer(a);
    lexer.nextToken();
    return S();
}

Parser::Parser() = default;
