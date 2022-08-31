#include <iostream>

using namespace std;

// Wrapper Classes
class MyArray
{
private:
    int *ar;
    const int CAPACITY;
    int length;

public:
    MyArray(int capacity) : CAPACITY(capacity)
    {
        ar = new int[CAPACITY];
        length = 0;
        for (int i = 0; i < CAPACITY; i++)
        {
            ar[i] = -9999;
        }
    }

    int getLength()
    {
        return length;
    }

    int getCapacity()
    {
        return CAPACITY;
    }

    bool isFull()
    {

        if (length == getCapacity())
            return true;

        return false;
    }

    // Delegates
    bool add(int x)
    {
        return insertAtLast(x);
    }

    bool insertAtLast(int x)
    {
        if (!isFull())
        {
            ar[length] = x;
            length++;
            return true;
        }

        return false;
    }
    //   lecture onwards

    void print()
    {

        for (int i = 0; i < getLength(); i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }

    // using shifting
    bool insertAtBeginning(int x)
    {
        return insertElementAtPosition(1, x);
    }

    void shiftRight(int pos)
    {
        int index = pos - 1;
        for (int i = getLength() ; i >= index; i--)
        {
            ar[i] = ar[i - 1];
        }
        ar[index] = -9999;
    }

    bool insertElementAtPosition(int pos, int element)
    {
        int index = pos - 1;

        // definitely check the conditions
        shiftRight(pos);

        ar[index] = element;

        length++;

        return true;
    }

    bool isEmpty()
    {
        return getLength() == 0;
    }

    int getElementAtPosition(int pos)
    {
        if (!isEmpty())
        {
            // pos -1 as   1 means 0 index
            return ar[pos - 1];
        }
        return -9999; // index
    }

    bool doesExist(int x)
    {

        if (!isEmpty())
        {
            for (int i = 0; i < getLength(); i++)
            {
                if (ar[i] == x)
                {
                    return true;
                }
            }
        }

        return false;
    }

    int find(int x)
    {
        if (doesExist(x))
        {
            for (int i = 0; i < getLength(); i++)
            {
                if (ar[i] == x)
                {
                    return i + 1;
                }
            }
        }

        return -9999;
    }
    // pos = 1
    void shiftLeft(int pos)
    {
        int index = pos - 1;

        for (int i = index; i < getLength(); i++)
        {
            ar[i] = ar[i + 1];
        }

        ar[getLength()] = -9999;
    }

    bool removeElementAtPosition(int pos)
    {

        shiftLeft(pos);

        length--;

        return true;
    }

    bool removeFirstElement()
    {
        if (!isEmpty())
        {
            return removeElementAtPosition(1);
        }

        return false;
    }
    bool removeLastElement()
    {
        if (!isEmpty())
        {
            return removeElementAtPosition(getLength());
        }

        return false;
    }

    bool removeElement(int x)
    {
        if (doesExist(x))
        {
            //code
            int pos = find(x);

            return removeElementAtPosition(pos);
        }
        return false;
    }

    // Delegate Function
    int getFirstElement()
    {
        return getElementAtPosition(1);
    }

    int getLastElement()
    {
        return getElementAtPosition(getLength());
    }

    void reverse()
    {
        for (int i = 0; i < getLength() / 2; i++)
        {
            int f = ar[i];
            int g = ar[(getLength() - 1) - i];

            ar[i] = g;
            ar[getLength() - 1 - i] = f;
        }
    }
};


int main()
{

    MyArray mar(33);
    mar.add(10);
    mar.add(20);
    mar.add(30);
    mar.add(40);
    mar.add(50);
    mar.add(60);
    mar.add(70);
    mar.add(80);
    mar.add(90);

    //  mar.print();
    //cout << mar.getElementAtPosition(mar.getLength() / 2);
    //cout << mar.removeElement(40) << endl;

    //mar.print();

    // OOP   SOLID Principle  : One of the five design principles intended to make software designs more understandable, flexible and maintainable.
    // Single Responsibility Principle
    // Simplicity is the ultimate sophistication
    // Seperation of Concern
    // KISS Principle : Keep it Stupid Simple , simplicity should be a key goal in design, and unnecessary complexity should be avoided.
    // DRY Principle : dont repeat yourself

    // a) mar.isEmpty();
    // b-1) int mar.find(45);
    // b-2)  mar.doesExist(45);
    // c) mar.getIndex(40);  if number exist then return the index else return -1
    // d) mar.print();  // it will print all the element of MyArray

    // e) mar.getFirstElement() //    it will return the first element of MyArray
    // f) mar.getLastElement()   // return the last element of the array
    //  bool f1)  mar.removeElement(x)
    // g) bool mar.removeFirstElement()  //
    // h) bool mar.removeLastElement()
    // i) bool mar.insertAtBeginning(x);
    // j) bool mar.insertAtLast(x);

    // k) mar.getElementAtPosition( pos );
    // l) mar.insertElementAtPosition( pos );
    // m) mar.removeElementAtPosition( pos );

    //cout << mar.getLength();

    // mar.print();

    // //    mar.removeElement(30);
    // mar.shiftLeft(1);
    // mar.shiftLeft(mar.getLength());
    // //mar.insertAtBeginning(9);

    mar.print();
    mar.reverse();
    mar.print();

    return 0;
}
