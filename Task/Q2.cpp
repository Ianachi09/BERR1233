#include <iostream>
#include <iomanip>

// Data Swap Function (ampersand, & used to pass by value)
void swapValue(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// Displaying Function (asterisk, * used to pass by references)
void displayArray(int *array1, int *array2, int size) {
     for (int i=0; i<size; i++) {
        std::cout << "A[" << i << "]: " << std::left << std::setw(15) << array1[i] << "R[" << i << "]: " << array2[i] << std::endl;
    }
}

// Blue Movement From Examples
void dataLeftRotation(int array1[], int array2[], int size) {
    //Keeping A[18] & B[0] as it is being overwritten
    int temp1 = array1[size-2];
    int temp2 = array2[0];

    //Shifting data by 3 indexes
    for (int i=size-2; i>0; i-=3) {
        array1[i] = array1[i-3];
    }

    for (int i=0; i<size; i+=3) {
        array2[i] = array2[i+3];
    }

    //Moving the overwritten data to next spot
    array1[0] = temp2;
    array2[size-2] = temp1;
}

// Green Movement From Examples
void dataRightRotation(int array1[], int array2[], int size) {
    // Keeping A[1] & R[19] as it is being overwritten
    int temp1 = array1[1];
    int temp2 = array2[size-1];

    // Shifting data by 3 indexes
    for (int i=size-1; i>0; i-=3) {
        array2[i] = array2[i-3];
    }

    for (int i=1; i<size; i+=3) {
        array1[i] = array1[i+3];
    }

    // Move the overwritten data to next spot
    array2[1] = temp1;
    array1[size-1] = temp2;
}

// Compiling All Movements In One Function
void dataMove(int array1[], int array2[], int size) {
    for (int i=2; i<size; i+=3) {
        swapValue(array1[i], array2[i]);
    }

    dataLeftRotation(array1, array2, size);
    dataRightRotation(array1, array2, size);
}

// Calling all the functions, Big O-Notation is O(1)
int main() {
    int A[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int R[20] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20};
    int size = 20;


    std::cout << "Before Movement\n";
    displayArray(A,R,size);

    dataMove(A, R, size);

    std::cout << "\n\nAfter Movement\n";
    displayArray(A,R,size);

    return 0;

}
