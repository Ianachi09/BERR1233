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
    cout << "------------------------------------"<< endl;
    cout << "Value of a before passByReference : " << a << endl; // prints the value of a before calling the function
    passByReference(a); // Calls the function passByReference and passes a by reference
    cout << "Value of a after passByReference : " << a << endl; // prints the value of a after calling the function
    cout << "------------------------------------"<< endl;
    cout << "Value of a before passByValue : " << a << endl; // prints the value of a before calling the function
    passByValue(a); // Calls the function passByValue and passes a by value (creates a copy of a and passes it to the function)
    cout << "Value of a after passByValue : " << a << endl; // prints the value of a after calling the function (a remains unchanged because it was passed by value)
    cout << "------------------------------------"<< endl; 
    cout << "Value of a before passByPointer : " << a << endl; // prints the value of a before calling the function
    passByPointer(&a); // Calls the function passByPointer and passes the address of a (passes a pointer to a)
    cout << "Value of a after passByPointer : " << a << endl; // prints the value of a after calling the function


    return 0;
}
/* * are used to declare pointer variables and to dereference(from address to the actual value) pointers. 
   & is used to get the address of a variable. 
   In this example, we declare an integer variable a and a pointer variable ptr that holds the address of a. 
   We then print the value of a, the address of a, the value of ptr (which is the address of a), and the value pointed to by ptr (which is the value of a). */

int passByReference(int &x) // This function takes an integer reference (& used to give the reference of x)
{
    x = x + 10; // Modifies the value of x by adding 10 to it
    return x; // Returns the modified value of x
}

int passByValue(int x) // This function takes an integer value (x is a normal integer variable)
{
    x = x + 10; // Modifies the value of x by adding 10 to it
    return x; // Returns the modified value of x
}

int passByPointer(int *x) // This function takes an integer pointer (* used to declare a pointer variable x)
{
    *x = *x + 10; // Modifies the value pointed to by x by adding 10 to it
    return *x; // Returns the modified value pointed to by x
}

