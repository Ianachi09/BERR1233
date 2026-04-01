#include <iostream>
using namespace std;
int main()
{
    int a = 10; // A is a normal interger variable
    int *ptr = &a; // * means pointer and & means address of a, so ptr is a pointer variable that holds the address of a

    cout << "Value of a : " << a << endl; // prints the value of a
    cout << "Address of a : " << &a << endl; // prints the address of a
    cout << "------------------------------------"<< endl;
    cout << "Value of ptr : " << ptr << endl; // prints the value of ptr, which is the address of a
    cout << "Value pointed to by ptr : " << *ptr << endl; // prints the value pointed to by ptr, which is the value of a
    return 0;
}

/* * are used to declare pointer variables and to dereference(from address to the actual value) pointers. 
   & is used to get the address of a variable. 
   In this example, we declare an integer variable a and a pointer variable ptr that holds the address of a. 
   We then print the value of a, the address of a, the value of ptr (which is the address of a), and the value pointed to by ptr (which is the value of a). */
