#include <bits/stdc++.h>
#include "calcParser.h"

void calcParser::updateInput(std::string &input) {
    lexer.updateInput(input);
}

std::vector<int> calcParser::parse() {
    lexer.nextToken();
    return E({});
}

std::vector<int> calcParser::E(std::vector<int> vect) {
    if (lexer.curToken() == NUM) {
        auto val1 = T(vect);

        vect = val1;
        auto val2 = E2(vect);

        auto retVal = val2;

        return retVal;
    } else if (lexer.curToken() == LBR) {
        auto val1 = T(vect);

        vect = val1;
        auto val2 = E2(vect);

        auto retVal = val2;

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

std::vector<int> calcParser::E2(std::vector<int> vect) {
    if (lexer.curToken() == PLUS) {
        if (lexer.curToken() != PLUS) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();

        auto val2 = T(vect);

        int a = vect.back();
        vect.pop_back();
        vect.push_back(a + val2[0]);
        auto val3 = E2(vect);

        auto retVal = val3;

        return retVal;
    } else if (lexer.curToken() == MINUS) {
        if (lexer.curToken() != MINUS) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();

        auto val2 = T(vect);

        int a = vect.back();
        vect.pop_back();
        vect.push_back(a - val2[0]);
        auto val3 = E2(vect);

        auto retVal = val3;

        return retVal;
    } else if (lexer.curToken() == END || lexer.curToken() == RBR || false) {
        auto retVal = std::vector<int>(vect);

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

std::vector<int> calcParser::F(std::vector<int> vect) {
    if (lexer.curToken() == LBR) {
        if (lexer.curToken() != LBR) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();
        auto val2 = E(vect);
        if (lexer.curToken() != RBR) throw std::runtime_error("bad_token");
        auto val3 = lexer.tokenString();
        lexer.nextToken();

        auto retVal = std::vector<int>(val2);

        return retVal;
    } else if (lexer.curToken() == NUM) {
        if (lexer.curToken() != NUM) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();

        std::vector<int> v;
        v.push_back(std::atoi(val1.data()));
        auto retVal = v;

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

std::vector<int> calcParser::P(std::vector<int> vect) {
    if (lexer.curToken() == NUM) {
        auto val1 = F(vect);

        vect = val1;
        auto val2 = P2(vect);

        auto retVal = val2;

        return retVal;
    } else if (lexer.curToken() == LBR) {
        auto val1 = F(vect);

        vect = val1;
        auto val2 = P2(vect);

        auto retVal = val2;

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

std::vector<int> calcParser::P2(std::vector<int> vect) {
    if (lexer.curToken() == POW) {
        if (lexer.curToken() != POW) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();

        auto val2 = F(vect);

        auto vect1 = vect;
        vect = val2;
        auto val3 = P2(vect);

        vect = vect1;
        int a = vect.back();
        vect.pop_back();
        int v = 1;
        for (int i = 0; i < val3[0]; i++) { v *= a; }
        vect.push_back(v);
        auto retVal = vect;

        return retVal;
    } else if (lexer.curToken() == MUL || lexer.curToken() == PLUS || lexer.curToken() == DIV ||
               lexer.curToken() == END || lexer.curToken() == RBR || lexer.curToken() == MINUS || false) {
        auto retVal = std::vector<int>(vect);

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

std::vector<int> calcParser::T(std::vector<int> vect) {
    if (lexer.curToken() == LBR) {
        auto val1 = P(vect);

        vect = val1;
        auto val2 = T2(vect);

        auto retVal = val2;

        return retVal;
    } else if (lexer.curToken() == NUM) {
        auto val1 = P(vect);

        vect = val1;
        auto val2 = T2(vect);

        auto retVal = val2;

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}

std::vector<int> calcParser::T2(std::vector<int> vect) {
    if (lexer.curToken() == MUL) {
        if (lexer.curToken() != MUL) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();

        auto val2 = P(vect);

        int a = vect.back();
        vect.pop_back();
        vect.push_back(a * val2[0]);
        auto val3 = T2(vect);

        auto retVal = val3;

        return retVal;
    } else if (lexer.curToken() == DIV) {
        if (lexer.curToken() != DIV) throw std::runtime_error("bad_token");
        auto val1 = lexer.tokenString();
        lexer.nextToken();

        auto val2 = P(vect);

        int a = vect.back();
        vect.pop_back();
        vect.push_back(a / val2[0]);
        auto val3 = T2(vect);

        auto retVal = val3;

        return retVal;
    } else if (lexer.curToken() == MINUS || lexer.curToken() == RBR || lexer.curToken() == PLUS ||
               lexer.curToken() == END || false) {
        auto retVal = std::vector<int>(vect);

        return retVal;
    } else {
        throw std::runtime_error("bad token");
    }
}
