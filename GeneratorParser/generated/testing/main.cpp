//
// Created by kranya on 22.12.2019.
//

#include <bits/stdc++.h>
#include "inputParser.h"
#include "../Tree.h"

int main() {
    inputParser parser;
    std::string str;
    getline(std::cin, str);
    parser.updateInput(str);
    Tree tree = parser.parse();
    std::set<int> se;
    printTree(tree, 0, se);
    return 0;
}