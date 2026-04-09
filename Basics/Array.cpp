#include <iostream>
#include <iterator> // for size() function
#include <algorithm>
#include <bits/stdc++.h>

// Custom Swap function
void swapValues(int &num1, int &num2) {
    int temp= num1;
    num1 = num2;
    num2 = temp;
}
    
/*
int main(){
    int B[5] = {6, 7, 8, 9, 10};
    int arr[5] = {1, 2, 3, 4, 5}; // 'Type of data' 'Name of array' ['Size of array'] (first value declared in brackets is the size of the array and the values in curly braces are the initial values of the array)
    std::cout << "Elements of the array: " << std::endl; // Prints the message for the array elements
    for(int i = 0; i < 5; i++) { // A for  loop that initializes i to 0, continues as long as i is less than 5, and increments i by 1 in each iteration
        std::cout << arr[i] << " "; // Prints the current element of the array followed by a space
    }

    for(int i = 0; i < 5; i++) { // A for  loop that initializes i to 0, continues as long as i is less than 5, and increments i by 1 in each iteration
        swapValues(arr[i], B[i]); // Prints the current element of the array followed by a space
    }

    std::cout << "Elements of the array (swapped): " << std::endl;
    for(int i = 0; i < 5; i++) { // A for  loop that initializes i to 0, continues as long as i is less than 5, and increments i by 1 in each iteration
        std::cout << arr[i] << " "; // Prints the current element of the array followed by a space
    }

    return 0;
}


//Array function that outputs even indexes only and odd indexes only, and also outputs the total sum of the values
int main() {
    int A[10] = {11,22,3,4,999,6,8,size-1,10,11};

    std::cout
     << A[1] << std::endl;

    std::cout
     << "Even Index" << std::endl;
    for (int i = 0; i < 10; i=i+2) {
      std::cout
       << "[" << i << "] : "<<  A[i] << std::endl;
    }

    std::cout
     << "Odd Index" << std::endl;
    for (int i = 1; i < 10; i=i+2) {
      std::cout
       << "[" << i << "] : "<<  A[i] << std::endl;
    }
    //Instead of using if function, can change the conditions in 'for loop' to;
    //Even : (int i=0; i<10; i+=2)
    //Odd : (int i=1; i<10; i+=2) 

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += A[i];
    }
    float mean = sum / size(A); // size() function can get the size of array

    std::cout
     << "Sum of all values : " << sum << std::endl;
    std::cout
     << "Mean : " << mean << std::endl;
    
    return 0;
}
    */

/*
// Array Printing Function For Copying and Swapping Only
void printArraySwap(int array1[], int array2[], int array3[], int size, bool ifTagged) {
     for (int i=0; i<size ; i++) {
        if (ifTagged == true) {
            if (array3[i] == array1[i]){ 
                std::cout << "A[" << i << "] :" << array1[i] << " \t" << "B[" << i << "] :" << array2[i] << " \t" << "C[" << i << "] :" << array3[i] << " (Copied)" << std::endl;
            } else if (array2[i] == array1[i]) {
                std::cout << "A[" << i << "] :" << array1[i] << " \t" << "B[" << i << "] :" << array2[i] << " (swapValuesped)\t" << "C[" << i << "] :" << array3[i] << " (swapValuesped)" << std::endl;
            } else {
                std::cout << "A[" << i << "] :" << array1[i] << " \t" << "B[" << i << "] :" << array2[i] << " \t" << "C[" << i << "] :" << array3[i] << std::endl;
            }
        } else {
             std::cout << "A[" << i << "] :" << array1[i] << " \t" << "B[" << i << "] :" << array2[i] << " \t" << "C[" << i << "] :" << array3[i] << std::endl;
        }
        }
    }

//Array movements
int main() {
    int size = 10;
    int A[size] = {10,1,2,3,4,5,44,20,11,20};
    int B[size] = {12,22,41,22,50,10,23,67,21,51};
    int C[size];
    bool isTagged = true;

    std::cout << "Before Movement" << std::endl;
    printArraySwap
 (A, B, C, size, isTagged);

    std::cout << std::endl;

    // Copy Arrays (Array A to C)
    for (int i=0; i<=size-1; i++) {
        C[i] = A[i];
    }

    std::cout << "After Copying" << std::endl;
    printArraySwap
 (A, B, C, size, isTagged);

    std::cout << std::endl;

    //Swapping Arrays (Array C and Array B)
    for (int i=0; i<=size-1; i++) {
        swapValues(C[i], B[i]);
    }

    std::cout
     << "After Swapping Between Arrays" << std::endl;
    printArraySwap
 (A, B, C, size, isTagged);
    isTagged = false;

    std::cout << std::endl;

    for (int i=0; i<=size-1; i+=2) {
        swapValues(A[i], A[i+1]);
    }
    
    std::cout
     << "After Second Swap" << std::endl;
    printArraySwap
 (A, B, C, size, isTagged);
    
    std::cout << std::endl;
    
    for (int i=0; i<=size-1; i++) {
        swapValues(B[i], C[size-1-i]);
    }
    
    std::cout << "After Intraarray Swap (Crossing Array A & Array B)" << std::endl;
    printArraySwap
 (A, B, C, size, isTagged);

    std::cout << std::endl;
    
    // Even swapValues
    for (int i=0; i<=size-1; i+=2) {
        swapValues(A[i], B[size-1-i]);
    }

    // Odd swapValues
    //for (int i=1; i<=size-1; i+=2) {
    //    swapValues(A[i], B[size-1-i]);
    //}
    
    std::cout << "After Intraarray swapValues (Even/Odd, need to set on backend, Only w/ A & B)" << std::endl;
    printArraySwap
 (A, B, C, size, isTagged);

    return 0;
}
    */
   
    /*
    // Bubble Sort Algorithm, compare 2 elements and swapValues if needed, then continue to next pair. Repeat for next array pass until sorted
   int bubble (int array[5], int size) {
        for (int step=0; step < size; step++) { // loop for whole array
       for (int i=0; i < size-step-1; i++) { // element stepping
           if (array[i] > array[i+1]) { // Comparing if element n is bigger than element n+1
               swapValues(array[i], array[i+1]);
           }
       }
      }
      return array[5];
   }

   // Insertion Sort
   int insertion (int array[5],int size) {
    for (int i=1; i<size; ++i) {
        int key = array[i]; // Last sorted element
        int j = i-1; // all previous elements before key
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j]; // Shifting elements
            j -= 1;
        }
        array[j+1] = key; // Setting new key
    }
    return array[5];
   }

   int main () {
    int array[5] = {3,2,5,1,4};
    int size = 5;

    std::cout
     << "Unsorted Array : \n";
    for (int i=0; i<=4; i++) {
        std::cout
         << array[i] <<" \t";
    }
    std::cout
     << std::endl;

    // Change the algorithm 
    insertion(array, size);

   std::cout
    << "Sorted Array : \n";
    for (int i=0; i<=4; i++) {
        std::cout
         << array[i] <<" \t";
    }
    return 0;
}
    */

// Array Rotation (Left Rotation)
int* arrayRotationLeft(int array[], int size, int step) {
    for (int i=0; i<step; i++) {
        int temp = array[0]; // Temporary variable to hold the first element of the array during rotation
        // Shift all elements to the left by one position
        for (int j=0; j<size-1; j++) { 
            array[j] = array[j+1];
        }
        array[size-1] = temp; // Place the first element at the end of the array
    }
    return array;
}

// Array Rotation (Right Rotation)
void arrayRotationRight(int array[], int size, int step) {
    for (int i=0; i<step; i++) {
        int temp = array[size-1]; // Temporary variable to hold the last element of the array during rotation
        // Shift all elements to the right by one position
        for (int j=size-1; j>0; j--) { 
            array[j] = array[j-1];
        }
        array[0] = temp; // Place the first element at the end of the array
    }
}

// Insertion
void insertElement(int& size, int array[], int newElement, int position) {
    size++;

    for (int i = size; i >= position; i--) {
        array[i] = array[i-1];
    }

    array[position] = newElement;
}

// Deletion
void deleteElement(int& size, int array[], int position) {

    for (int i = position; i < size; i++) {
        array[i] = array[i+1];
    }

    size--;
}

// Array Printing Function
void printArray(int array[], int size) {
    for (int i=0; i<size; i++) {
        std::cout << "A[" << i << "]: " << array[i] << std::endl;
    }
}

// Dynamic Arrays
int main() {
    int size; // Variable to hold the size of the array
    int leftStep = 2;
    int rightStep = 2;
    std::cout << "Enter the array size: ";
    std::cin >> size;

    int *A; // Pointer to an array, Data types can be changed
    A = new int[size]; // Dynamically allocate an array of size 'size', also data types can be changed (same as declaring pointers to array)

    // Initialize the array with values (for demonstration, we can fill it with sequential numbers starting from 1)
    for (int i=0; i<size; i++) {
        A[i] = i+1;
    }

    std::cout << "\nBefore Rotation: " << std::endl;
    printArray(A, size);

    arrayRotationLeft(A, size, leftStep);

    std::cout << "\nAfter Left Rotation(2): " << std::endl;
    printArray(A, size);

    arrayRotationRight(A, size, rightStep);

    std::cout << "\nAfter Right Rotation(2): " << std::endl;
    printArray(A, size);

    int newValue;
    std::cout << "\nEnter new value to be added: ";
    std::cin >> newValue;
    int pos;
    std::cout << "Enter the index to be added on: ";
    std::cin >> pos;

    insertElement(size, A, newValue, pos);

    std::cout << "\nAfter Insertion: " << std::endl;
    printArray(A, size);

    std::cout << "\nEnter the index to be removed: ";
    std::cin >> pos;

    deleteElement(size, A, pos);

    std::cout << "\nAfter Deletion: " << std::endl;
    printArray(A, size);

    delete[] A;
}