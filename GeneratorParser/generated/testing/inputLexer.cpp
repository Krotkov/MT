#include <bits/stdc++.h>
#include "inputLexer.h"

inputLexer::inputLexer() {
    curPos = 0;
    _curToken = BEGIN;
    skips = {  };
}

Token inputLexer::curToken() {
    return _curToken;
}

void inputLexer::updateInput(const std::string& newInput) {
    input = newInput;
    curPos = 0;
}

std::string inputLexer::tokenString() {
    return _tokenString;
}

void inputLexer::nextToken() {
    Token t = findNextToken();
    while (skips.find(t) != skips.end()) {
        t = findNextToken();
    }
    _curToken = t;
}

Token inputLexer::findNextToken() {
    std::smatch m;
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^[ \t\n]+)"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return WHITE;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^[1-9][0-9]+)"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return NUM;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^\+)"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return PLUS;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^\*)"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return MUL;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^()"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return LBR;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex(R"(^))"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return RBR;
    }
    if (std::regex_search(input.cbegin() + curPos, input.cend(), m, std::regex("$"))) {
        curPos += m.str().size();
        _tokenString = m.str();
        return END;
    }
    throw std::runtime_error("bad argument");
}
