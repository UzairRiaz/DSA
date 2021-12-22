//Sir Abdul wahab's code: https://gist.github.com/cs-abdulwahab/a05fff93647ab7f3b9713ecd3bbf71f6

#include <iostream>

using namespace std;

class Node{
    int val = NULL;
    Node *next = NULL;
public:
    Node(int val): val(val){}
    void setNext(Node* next){
        this->next = next;
    };
    Node *getNext(){
        return this->next;
    };
    void setData(int val) {
        this->val = val;
    }
    int getData(){
        return this->val;
    }
};

class SingllyLinkedList{
    Node *head = NULL;
    Node *tail = NULL;
    int length = 0;
public:
    SingllyLinkedList(){
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }
    //check for empty List
    bool isEmpty(){
        return this->head ? false : true;
    };
    //get Node
    Node *getNode(int pos) {
        if(!isEmpty()){
            Node * tempNode = this->head;
            for (int i = 1; i < pos; i++) {
                tempNode = tempNode->getNext();
            }
            return tempNode;
        }
        return NULL;
    }
    // remove specific node
    void removeNode(int n) {
        if(!isEmpty()){
            int ind = this->search(n);
            Node * Prev = this->getNode(ind - 1);
            Node * NodeToRemove = this->getNode(ind);
            Node * next = this->getNode(ind + 1);
            
            Prev->setNext(next);
            delete NodeToRemove;
            length--;
        }
    }
    //insert element at the end
    void insertAtEnd(int val){
        Node *node = new Node(val);
        if(isEmpty()){
            this->head = node;
            this->tail = node;
            this->length++;
        } else {
//            Node *tempNode = this->getNode(this->length -1);
            Node *slast = this->tail;
            this->tail = node;
            slast->setNext(tail);
            
//            tempNode = this->getNode(this->length);
//            tempNode->setNext(newNode);
            this->length++;
        }
    }
    //remove element from end
    void removeFromEnd(){
        if(!isEmpty()){
            Node* slast = this->getNode(this->length -1);
            delete this->tail;
            this->tail = slast;
            this->length--;
        }
    }
    //insert element at the start
    void insertAtBeginning(int val){
        Node *node = new Node(val);
        if(isEmpty()){
            this->head = node;
            this->tail = this->head;
            this->length++;
        } else {
            
            Node *temp = head;
            
            node->setNext(temp);
            head = node;
            
            
            
            
            
            length++;
        }
    }
    // make list circular
    void convertToCircular() {
        tail->setNext(this->head);
    }
    
    
    //remove element from the start
    void removeFromBeginning(){
        if(!isEmpty()){
            Node * tempHead = this->getNode(2);
//            this->head->setNext(NULL);
//            this->head->setData(NULL);
//            this->head = tempHead;
            
            delete head;
            this->head = tempHead;
            this->length--;
        }
    }
    void insert(int val, int pos) {
        if(pos == 1) {
            this->insertAtBeginning(val);
        } else {
            Node* preNode = this->getNode(pos - 1);
            Node* newNode = new Node(val);
            Node* nextNode = this->getNode(pos);
            preNode->setNext(newNode);
            newNode->setNext(nextNode);
            this->length++;
        }
    }
    //getSize
    int getLength() {
        return this->length;
    }
    //print the List
    void print(){
        if(isEmpty()) {
            cout << "[ ]" << endl;
        } else {
            Node *tempNode = this->head;
            cout << "[";
            for (int i = 0; i < this->length -1; i++) {
                cout << " " << tempNode->getData();
                tempNode = tempNode->getNext();
            }
            cout << " ]" << endl;
        }
    }
    //search a value and return its position
    int search(int n){
        Node *currentNode = this->head;
        for(int i = 0; i < this->length; i++){
            if(currentNode->getData() == n) {
                return i+1;
            }
            currentNode=currentNode->getNext();
        }
        return -1;
    }
    // check if the val is element
    bool isElement(int n){
        Node *currentNode = this->head;
        for(int i = 0; i < this->length; i++){
            if(currentNode->getData() == n) {
                return true;
            }
            currentNode=currentNode->getNext();
        }
        return false;
    }
    //concatination
    SingllyLinkedList* concatinate(const SingllyLinkedList &L){
        this->tail->setNext(L.head);
        this->length += L.length;
        return this;
    }
    //reverse
    void reverse()
        {
            Node* current = this->head;
            Node *prev = NULL, *next = NULL;
            for(int i = 0; i < this->length -1; i++) {
                next = current->getNext();
                current->setNext(prev);
                prev = current;
                current = next;
            }
            head = prev;
        }
    //sorting the linked list
    void sort(){
        Node* currentNode = this->head;
        Node* testNode = currentNode->getNext();
        int tempCurrentData = NULL;
        for(int i = 1 ; i <= length; i++) {
            for (int k = i; k <= length-1; k++) {
                testNode = this->getNode(k);
                if(currentNode->getData() > testNode->getData()){
                    tempCurrentData = currentNode->getData();
                    currentNode->setData(testNode->getData());
                    testNode->setData(tempCurrentData);
                    
                }
            }
            currentNode = getNode(i);
        }
            
    }
    
    // Remove duplicate
    
    void removeDuplicate(){
        for(int i = 1; i <= length; i++){
            Node *tempNode = getNode(i);
            int data = tempNode->getData();
            for(int j = i+1; j <= length; j++){
                if(data == getNode(j)->getData()){
                    removeNode(j);
                }
            }
        }
    }
};

int main() {
    SingllyLinkedList List;
    List.insertAtBeginning(10);
    List.insertAtEnd(5);
    List.insertAtEnd(6);
    List.insertAtEnd(7);
    List.insertAtEnd(3);
    List.insertAtBeginning(9);
    List.removeFromEnd();
    List.insert(99, 3);
    List.print();
    SingllyLinkedList List2;
    List2.insertAtBeginning(10);
    List2.insertAtEnd(5);
    List2.insertAtEnd(6);
    List2.insertAtEnd(3);
    List.insertAtBeginning(8);
    List2.removeFromEnd();
    List.removeFromBeginning();
    List.concatinate(List2);
    List.print();
   List.reverse();
//    List.removeFromBeginning();
//    List.removeFromEnd();
    List.print();
    List.sort();
    
    List.print();
}
