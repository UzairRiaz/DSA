#include <iostream>
using namespace std;
class Node
{
// private:
public:
    int x;
    int *ptr;
    Node *np;
// public:
    Node(int x)
    {
        this->x = x; //default
        ptr = NULL;
        np = NULL;
    }
    void setX(int x) //Camel case
    {
        this->x = x;
    }
    void setPtr(int *ptr)
    {
        this->ptr = ptr;
    }
    void setNode(Node *np)
    {
    this->np = np;
    }
    void print()
    {
        cout << "x = " << x << endl;
        cout << "Value of dynamic x = " << *ptr<<endl;
        // cout << *np << endl;
        // printnode(np);
    }
    void printnode( Node *np )
    {
        /* cout << this->np.x;     ---- mistakes ----
        cout << *np.x;
        cout << *np.x;
        cout << this->*np.print();  ---- mistakes ---- */

        np->print();   // getting 3.. vlaue of n2.
        
    }
};
int main()
{
    Node n1(2);
    
    Node n2(500);
    int *pointer = new int(3000);
    n2.setPtr(pointer);
    cout <<" n1 showing data of n2 : \n" ;
    n1.setNode(&n2);
    cout << &n2 << endl;
    n1.printnode(&n2);  // printnode() prints print() in implementation
}
