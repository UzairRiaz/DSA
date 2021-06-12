//
//  Node.hpp
//  Tree
//
//  Created by Umair Riaz on 01/06/2021.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node {
private:
    int value;
    Node* left = NULL;
    Node* right = NULL;
public:
    Node(int val);
    //setters
    void setLeft(Node* l);
    void setRight(Node* r);
    //getters
    Node* getLeft();
    Node* getRight();
    int getValue();
};

#endif /* Node_hpp */
