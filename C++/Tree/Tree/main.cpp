//
//  main.cpp
//  Tree
//
//  Created by Umair Riaz on 01/06/2021.
//

#include <iostream>
#include "Tree.hpp"

using namespace std;

int main() {
    Tree t1(4);
    t1.insert(9);
    t1.insert(3);
    t1.insert(5);
    cout << "Infix: ";
    t1.printInfix();
    cout << "Postfix: ";
    t1.printPostfix();
    cout << "Prefix: ";
    t1.printPrefix();
    return 0;
}
