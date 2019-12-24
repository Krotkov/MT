#include <bits/stdc++.h>
#include "pascalLexer.h"

pascalLexer::pascalLexer() {
    curPos = 0;
    _curToken = BEGIN;
    skips = { WHITE };
}

Token pascalLexer::curToken() {
    return _curToken;
}

void pascalLexer::updateInput(const std::string& newInput) {
    input = newInput;
    curPos = 0;
}

std::string pascalLexer::tokenString() {
    return _tokenString;
}

void pascalLexer::nextToken() {
    Token t = findNextToken();
    while (skips.find(t) != skips.end()) {
        t = findNextToken();
    }
    _curToken = t;
}

Token pascalLexer::findNextToken() {
    std::smatch m;
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^([ \t\n]+))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return WHITE;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(function))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return FUNCTION;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(procedure))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return PROCEDURE;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\())"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return LBR;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\)))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return RBR;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(:))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return COLON;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(;))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return SEMICOLON;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(\,))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return COMMA;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^(Integer|Boolean|Float))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return TYPE;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^([a-zA-z]+))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return NAME;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex("$"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return END;
    }
    throw std::runtime_error("bad argument");
}
