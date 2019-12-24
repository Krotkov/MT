//
// Created by kranya on 22.12.2019.
//

#include <bits/stdc++.h>
#include "calcParser.h"
#include "../Tree.h"

int main() {
    calcParser parser;
    std::string str;
    getline(std::cin, str);
    parser.updateInput(str);
    Tree tree = parser.parse();
    std::set<int> se;
    printTree(tree, 0, se);
    return 0;
}