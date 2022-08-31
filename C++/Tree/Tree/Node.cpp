//
//  Node.cpp
//  Tree
//
//  Created by Umair Riaz on 01/06/2021.
//

#include "Node.hpp"
#include <iostream>

using namespace std;

Node::Node(int val) {
    this->value = val;
    this->setLeft(NULL);
    this->setRight(NULL);
}

int Node::getValue() {
    return this->value;
}

void Node::setLeft(Node *l){
    this->left = l;
}

void Node::setRight(Node *r) {
    this->right = r;
}

Node* Node::getRight() {return this->right;}
Node* Node::getLeft() {return this->left;}
