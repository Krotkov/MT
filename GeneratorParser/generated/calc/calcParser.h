#pragma once
#include <bits/stdc++.h>
#include "calcLexer.h"
#include <bits/stdc++.h>
#include "../Tree.h"

class calcParser {
    calcLexer lexer;
    std::vector<int> E(std::vector<int> vect);
    std::vector<int> E2(std::vector<int> vect);
    std::vector<int> F(std::vector<int> vect);
    std::vector<int> P(std::vector<int> vect);
    std::vector<int> P2(std::vector<int> vect);
    std::vector<int> T(std::vector<int> vect);
    std::vector<int> T2(std::vector<int> vect);
public:
    calcParser() = default;
    void updateInput(std::string& input);
    std::vector<int> parse();
};
