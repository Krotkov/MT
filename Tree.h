//
// Created by kranya on 09.12.2019.
//

#ifndef MT_TREE_H
#define MT_TREE_H


#include <string>
#include <vector>
#include <set>

class Tree {
    std::string node;

    std::vector <Tree> children;

public:
    explicit Tree (std::string node);
    Tree (std::string node , std::vector<Tree> c);

    Tree();

    friend void printTree(Tree tree, int num, std::set<int>& se);
};


#endif //MT_TREE_H
