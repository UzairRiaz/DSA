#include<iostream>

using namespace std;
template <typename T>

class BufferArray {
private:
    int size;
    int capacity;
    T* buffer;
    int head;
    int tail;

public:
    BufferArray() {
        this->size = 0;
        this->capacity = size + 10;
        this->buffer = new T[this->capacity];
        this->head = 3;
        this->tail = this->head + 1;
    }

    ~BufferArray() {
        delete[] buffer;
    }

    bool isEmpty() {
        return head == tail;
    }

    bool isFull() {
        return head == tail - 1;
    }

    void IncreaseCapacity() {
            // resize the buffer
            int newCapacity = capacity + 10;
            T* newBuffer = new T[newCapacity];

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

    bool push(T value) {
        if(this->isFull()) {
                this->IncreaseCapacity();
        }
        if (size == 0){
            buffer[head] = value;
            tail++;
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

    T pop() {
        // remove the last value from the buffer
        if (size == 0) {
            return -1;
        }
        if (tail == 0) {
            tail = capacity - 1;
            size--;
            return buffer[tail];
        }
        tail--;
        size--;
        return buffer[tail];
    }

    T peek() {
        // return the last value from the buffer
        if (size == 0) {
            return -1;
        }
        if (tail == 0) {
            return buffer[capacity - 1];
        }
        return buffer[tail - 1];
    }

    T shift() {
        // remove the first value from the buffer
        if (size == 0) {
            return -1;
        }
        if (head == capacity - 1) {
            head = 0;
            size--;
            return buffer[capacity - 1];
        }
        head++;
        size--;
        return buffer[head - 1];
    }

    bool unshift(T value) {
        if (this->isFull()) {
            this->IncreaseCapacity();
        }
        if (size == 0){
            buffer[head] = value;
            size++;
            return true;
        }
        if (head == 0) {
            head = capacity - 1;
            buffer[head] = value;
            size++;
            return true;
        }
        buffer[head - 1] = value;
        head--;
        size++;
        return true;
    }

    T& operator[](int index) {
        if (head + index >= capacity) {
            return buffer[head + index - capacity];
        } 
        return buffer[head + index];
    };

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

    void map(void (*func)(T)) {
        for(this-> head; head < tail; head++) {
            func(buffer[head]);
        }
    }

    T* forEach(T* (*func)(T)) {
        T* result = new T[size];
        for(this-> head; head < tail; head++) {
            result[head] = func(buffer[head]);
        }
        return result;
    }
};

int main(){
    BufferArray<int> buffer;
    buffer.push('a');
    buffer.print();
    buffer.push('b');
    buffer.print();

    buffer.push('c');
    buffer.print();

    buffer.push('4');
    buffer.print();

    buffer.push('5');
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

    buffer.push(11);
    buffer.print();

    buffer.push(12);
    buffer.print();

    cout << buffer[1] << endl;

    buffer.shift();
    buffer.print();

    // buffer.map([](int c) {
    //     cout << c << endl;
    // });

    // int *result = buffer.forEach((int c) {
    //     return c * 2;
    // });
    // for (int i = 0; i < result.length(); i++) {
    //     cout << result[i] << endl;
    // }
    return 0;
}

// Path: main.cpp