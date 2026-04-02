#include <iostream>
#include <iterator> // for size() function
using namespace std;

/*
int main(){
    int arr[5] = {1, 2, 3, 4, 5}; // 'Type of data' 'Name of array' ['Size of array'] (first value declared in brackets is the size of the array and the values in curly braces are the initial values of the array)
    cout << "Elements of the array: " << endl; // Prints the message for the array elements
    for(int i = 0; i < 5; i++) { // A for  loop that initializes i to 0, continues as long as i is less than 5, and increments i by 1 in each iteration
        cout << arr[i] << " "; // Prints the current element of the array followed by a space
    }
    return 0;
}
*/

/* Array function that outputs even indexes only and odd indexes only, and also outputs the total sum of the values
int main() {
    int A[10] = {11,22,3,4,999,6,8,9,10,11};

    cout << "Even Index" << endl;
    for (int i = 0; i < 10; i++) {
        if ( i%2 == 0) {
            cout << "[" << i << "] : "<<  A[i] << endl;
        }
    }

    cout << "Odd Index" << endl;
    for (int i = 0; i < 10; i++) {
        if ( i%2 != 0) {
            cout << "[" << i << "] : "<<  A[i] << endl;
        }
    }
    //Instead of using if function, can change the conditions in 'for loop' to;
    //Even : (int i=0; i<10; i+=2)
    //Odd : (int i=1; i<10; i+=2) 

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += A[i];
    }
    float mean = sum / size(A); // size() function can get the size of array

    cout << "Sum of all values : " << sum << endl;
    cout << "Mean : " << mean << endl;
    
    return 0;
}
*/

// Array movements
int main(){
    int A[6] = {10,1,2,3,4,5};
    int B[6];

    cout << "Before Movement" << endl;
    for (int i=0; i<=5; i++) {
        cout << "A[" << i << "] :" << A[i] << " \t" << "B[" << i << "] :" << B[i] << endl;
    }

    cout << endl;

    //Copy Arrays
    for (int i=0; i<=5; i++) {
        B[i] = A[i];
    }

    cout << endl;

    cout << "After Movement" << endl;
    for (int i=0; i<=5; i++) {
        cout << "A[" << i << "] :" << A[i] << " \t" << "B[" << i << "] :" << B[i] << endl;
    }

    return 0;
}


