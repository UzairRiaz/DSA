#include <iostream>

using namespace std;

class Stack{
private:
    int *arr;
    int length;
    int capacity;
public:
    Stack(int cap): capacity(cap)
    {
        this->length=0;
        arr = new int[cap];
        for (int i = 0; i < capacity; i++) {
            arr[i] = -9999;
        }
    }
    bool isFull() {
        if(this->capacity == this->length){
            return true;
        }
        return false;
    }
    int getElement(int i){
        return arr[i];
    }
    
    bool isEmpty(){
        if(this->length == 0){
            return true;
        }
        return false;
    }
    
    bool push(int n){
        if(!isFull()){
            arr[this->length] = n;
            this->length++;
            return true;
        }
        return false;
    }
    
    int pop() {
        int val = arr[this->length];
        arr[this->length] = -9999;
        this->length--;
        return val;
    }
    int onTop(){
        if(!isEmpty()){
            return this->arr[this->length];
        }
        return -9999;
    }
    
    void sort() {
        bool swapped = false;
        do {
            for(int i = 0; i < length -1; i++) {
                int a = arr[i];
                int b = arr[i+1];
                if(a > b) {
                    arr[i] = b;
                    arr[i+1] = a;
                    swapped = true;
                } else {
                    swapped = false;
                }
            }
        } while (swapped);
    }
    void print() {
        for(int i = 0; i < length; i++){
            cout << " " << arr[i] << " ";
        };
    }
};

int main() {
    Stack s1(5);
    s1.push(5);
    s1.push(2);
    s1.push(10);
    s1.push(2);
    s1.push(9);
    s1.pop();
    s1.pop();
    s1.print();
    return 0;
}
