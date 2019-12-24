#pragma once
#include <bits/stdc++.h>
#include "pascalLexer.h"
#include <bits/stdc++.h>
#include "../Tree.h"

class pascalParser {
    pascalLexer lexer;
    Tree A();
    Tree AS();
    Tree AS2();
    Tree S();
    Tree VS();
    Tree VS2();
public:
    pascalParser() = default;
    void updateInput(std::string& input);
    Tree parse();
};
