//
//  Tree.cpp
//  Tree
//
//  Created by Umair Riaz on 01/06/2021.
//

#include "Tree.hpp"
#include "Node.hpp"
#include <iostream>

using namespace std;

Tree::Tree(int val){
    Node* newNode = new Node(val);
    this->root = newNode;
}

void Tree::insert(int val){
    Node * current = this->root;
        int currentValue = current->getValue();
    while (true) {
        if(currentValue > val) {
            if(current->getLeft() == NULL) {
                Node * newNode = new Node(val);
                current->setLeft(newNode);
                return;
            } else {
                current = current->getLeft();
            }
        } else {
            if(current->getRight() == NULL) {
                Node * newNode = new Node(val);
                current->setRight(newNode);
                return;
            } else {
                current = current->getRight();
            }
        }
    }
        
}

void Tree::printInfix() {
    Node * n = this->root;
    if (n == NULL) return;
    
    Tree::printInfix(n->getLeft());
    cout << n->getValue() << endl;
    Tree::printInfix(n->getRight());
}

void Tree::printInfix(Node *n) {
    if (n == NULL) return;
    
    Tree::printInfix(n->getLeft());
    cout << n->getValue() << endl;
    Tree::printInfix(n->getRight());
}

void Tree::printPostfix() {
    Node * n = this->root;
    if (n == NULL) return;
    
    Tree::printPostfix(n->getLeft());
    Tree::printPostfix(n->getRight());
    cout << n->getValue() << endl;
}

void Tree::printPostfix(Node *n) {
    if (n == NULL) return;
    
    Tree::printPostfix(n->getLeft());
    Tree::printPostfix(n->getRight());
    cout << n->getValue() << endl;
    
}

void Tree::printPrefix() {
    Node * n = this->root;
    if (n == NULL) return;
    
    cout << n->getValue() << endl;
    Tree::printPrefix(n->getLeft());
    Tree::printPrefix(n->getRight());
}

void Tree::printPrefix(Node *n) {
    if (n == NULL) return;
    
    cout << n->getValue() << endl;
    Tree::printPrefix(n->getLeft());
    Tree::printPrefix(n->getRight());
}
