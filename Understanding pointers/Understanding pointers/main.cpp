#include<iostream>
using namespace std;
int main()
{
    cout<<"\tCS201 Assignment 1 Solution Spring 2021 (VUStudents.pk)" <<endl;
    // Solving Expression
    int x, y, z;
    x=2;
    y = 1;
    z=(x*x) + (2*x*y) - (x/y);
    cout<< "After evalution of given exression the value of z =" << z << endl;
    //student 10 and Anylizing
    string ID = "BC";
    int id2 = 123456781;
    string Name = "VUStudents.pk";
    int lastdigit;
    int Gotnumber;
    //Evaluation of ID
    lastdigit = id2 % 10;
    cout<<"Last Digit of my VU ID is " << lastdigit << endl;
    Gotnumber = 2 + lastdigit;
    // If eLse Loop
    // Adding Last digit of ID and Z and print resuLt Odd or Even
    string test;
    int n = 1;
    if ((lastdigit % 2) == 0)
    {
        test = " even";
        cout<< "I got an" << test << "number"<<Gotnumber <<endl;
        while (n <= Gotnumber)
        {
            cout << "Iteration:" << n <<endl;
            cout <<"My Name is: " <<Name <<endl;
            n++;
        }
    }
    else
    {
        test = "odd";
        cout<<"I got an" <<test <<"number"<<Gotnumber <<endl;
        while (n <= Gotnumber)
        {
            cout << "Iteration:" <<n <<endl;
            cout <<"My Vu ID is:" <<ID <<id2 <<endl;
            n++;
        }
    }
}
