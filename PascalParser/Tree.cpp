//
// Created by kranya on 09.12.2019.
//

#include "Tree.h"

#include <utility>
#include <iostream>

Tree::Tree(std::string node) {
    this->node = std::move(node);
    this->children.resize(0);
}

Tree::Tree(std::string node, std::vector<Tree> c) {
    this->node = std::move(node);
    this->children = std::move(c);
}

Tree::Tree() {
    this->node = "";
    this->children.resize(0);
}

void printTree(Tree tree, int num, std::set<int> &se) {
    for (int i = 0; i < num; i++) {
        if (se.find(i) != se.end()) std::cout << "|";
        else std::cout << " ";
    }
    std::cout << "|";
    std::cout << tree.node << "\n";
    se.insert(num + 5);
    for (size_t j = 0; j < tree.children.size(); j++) {
        if (j + 1 == tree.children.size()) se.erase(num + 5);
        printTree(tree.children[j], num + 5, se);
    }
    se.erase(num + 5);
}
