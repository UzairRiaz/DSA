#include <iostream>

using namespace std;

class Node {
    int val;
    Node *next = NULL;
public:
    Node(int x) {
        this->val = x;
    }
    Node* getNext() {
        return next;
    }
    void setNext(Node* next){
        this->next = next;
    }
    int getData(){
        return this->val;
    }
    void setData(int x) {
        this-> val = x;
    }
};

class Queue {
    Node *queue;
    int length;
    Node *head = NULL;
    Node *tail = NULL;
public:
    Queue(){
        this->length = 0;
    }
    bool isEmpty(){
        return this->length < 1 ? true : false;
    }
    void enqueue(int n){
        Node* newNode = new Node(n);
        if(isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
            this->length++;
        } else {
            Node *slast = this->tail;
            slast->setNext(newNode);
            this->tail = newNode;
            this->length++;
        }
    }
    int dequeue(){
        if(isEmpty()){
            return -9999;
        } else {
            int val = this->head->getData();
            Node* newHead = this->head->getNext();
            this->head = newHead;
            this->length--;
            return val;
        }
    }
    
    void print(){
        Node *current = this->head;
        while(current != NULL) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
    
};

int main() {
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(7);
    q1.enqueue(24);
    cout << q1.dequeue() <<endl;
    q1.print();
    return 0;
}
