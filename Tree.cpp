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

void printTree(Tree tree, int num) {
    for (int i = 0; i < num; i++) {
        std::cout << " ";
    }
    std::cout << tree.node << "\n";
    for (const auto& j: tree.children) {
        printTree(j, num+5);
    }
}
