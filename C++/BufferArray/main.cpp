#include<iostream>

using namespace std;

class BufferArray {
private:
    int size;
    int capacity;
    int* buffer;
    int head;
    int tail;

public:
    BufferArray() {
        this->size = 0;
        this->capacity = size + 10;
        this->buffer = new int[this->capacity];
        this->head = 3;
        this->tail = this->head + 1;
    }

    ~BufferArray() {
        delete[] buffer;
    }

    bool isEmpty() {
        return head == tail;
    }

    bool push(int value) {
        // add value to the end of the buffer
        if (size == capacity) {
            // resize the buffer
            int newCapacity = capacity + 10;
            int* newBuffer = new int[newCapacity];

            int current = head;
            int newCurrent = 3;
            for (int i = 0; i < size; i++) {
                newBuffer[newCurrent] = buffer[current];
                current++;
                newCurrent++;
                if (current == capacity) {
                    current = 0;
                }
            }

            delete[] buffer;
            buffer = newBuffer;
            capacity = newCapacity;
            head = 3;
            tail = head + size;
        }
        if (size == 0) {
            cout << "size is 0" << endl;
            buffer[head] = value;
            size++;
            return true;
        }
        if (tail == capacity) {
            tail = 0;
            buffer[tail] = value;
            size++;
            tail++;
            return true;
        }
        buffer[tail] = value;
        tail++;
        size++;
        return true;
    }

    int length() {
        return size;
    }

    void print() {
        int current = head;
        cout << "head: " << head << endl;
        cout << "tail: " << tail << endl;
        cout << "capacity: " << capacity << endl;
        cout << "size: " << size << endl;
        for (int i = 0; i < size; i++) {
            cout << buffer[current] << " ";
            current++;
            if (current == capacity) {
                current = 0;
            }
        }
        cout << endl;
    }

    void printBuffer() {
        for (int i = 0; i < capacity; i++) {
            cout << buffer[i] << " ";
        }
    }
};

int main(){
    BufferArray buffer;
 buffer.push(1);
    buffer.print();
 buffer.push(2);
    buffer.print();

 buffer.push(3);
    buffer.print();

 buffer.push(4);
    buffer.print();

 buffer.push(5);
    buffer.print();

 buffer.push(6);
    buffer.print();

 buffer.push(7);
    buffer.print();
    
 buffer.push(8);
    buffer.print();

 buffer.push(9);
    buffer.print();

    buffer.push(10);
    buffer.print();
    buffer.printBuffer();

    buffer.push(11);
    buffer.print();

    buffer.push(12);
    buffer.print();

    buffer.printBuffer();
    return 0;
}

// Path: main.cpp