#pragma once
#include <bits/stdc++.h>
#include "pascalLexer.h"
#include <bits/stdc++.h>
#include "../Tree.h"

class pascalParser {
    pascalLexer lexer;
    Tree A(std::string type);
    Tree AS(std::string type);
    Tree AS2(std::string type);
    Tree S(std::string type);
    Tree VS(std::string type);
    Tree VS2(std::string type);
public:
    pascalParser() = default;
    void updateInput(std::string& input);
    Tree parse();
};
