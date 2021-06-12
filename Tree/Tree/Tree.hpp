#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "Node.hpp"

class Tree {
private:
    Node* root = NULL;
    Node* left = NULL;
    Node* right = NULL;
public:
    Tree(int val);
    void insert(int val);
    void printInfix();
    void printInfix(Node * n);
    void printPostfix();
    void printPostfix(Node * n);
    void printPrefix();
    void printPrefix(Node * n);
};


#endif /* Tree_hpp */
