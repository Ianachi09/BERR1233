#include <iostream>
//#include <iomanip>

// Data Swap Function (ampersand, & used to pass by value)
void swapValue(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

//Displaying Function (asterisk, * used to pass by references)
void displayArray(int *array1, int *array2, int size) {
     for (int i=0; i<size; i++) {
        std::cout << "A[" << i << "]: " << array1[i] << "\t\tC[" << i << "]: " << array2[i] << std::endl;
    }
}

// Compiling All Movements Into One Function
void dataMove(int array1[], int array2[], int size) {
    for (int i=0; i<size; i+=3) {
        swapValue(array1[i], array2[i+2]);
        swapValue(array1[i+1], array2[i+1]);
        swapValue(array1[i+2], array2[i]);
    }
}

// Calling all the functions, Big O-Notation is O(1)
int main() {
    int A[18] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    int C[18] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18};
    int size = 18;

    std::cout << "Before Movement\n";
    displayArray(A,C,size);

    dataMove(A, C, size);

    std::cout << "\n\nAfter Movement\n";
    displayArray(A,C,size);

    return 0;
}
