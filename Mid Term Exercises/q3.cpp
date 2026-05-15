#include <iostream>

void swapValue(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void dataMove(int arrayA[], int arrayB[], int arrayC[], int sizeA, int sizeB, int sizeC) {
    for(int i=0; i<8; i+=2) {
        swapValue(arrayB[i], arrayC[i+1]);
        swapValue(arrayB[i+1], arrayC[i]);
    }

    int temp1 = arrayA[0];
    int temp2 = arrayB[17];

    for(int i=0; i<sizeA-1; i++) {
        arrayA[i] = arrayA[i+1];
    }

    for(int i=sizeB-1; i>9; i-=2) {
        arrayB[i] = arrayB[i-2];
    }

    arrayB[9] = temp1;
    arrayA[9] = temp2;
}

void displayArray(int *arrayA, int *arrayB, int *arrayC, int sizeA, int sizeB, int sizeC) {
    for (int i=0; i<sizeA; i++) {
        std::cout << "A[" << i << "]: " << arrayA[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i=0; i<sizeB; i++) {
        std::cout << "B[" << i << "]: " << arrayB[i] << std::endl;
    }
    std::cout << std::endl;
    for (int i=0; i<sizeC; i++) {
        std::cout << "C[" << i << "]: " << arrayC[i] << std::endl;
    }
}

int main() {
    int sizeA = 10;
    int sizeB = 18;
    int sizeC = 8;

    int arrayA[10] = {1,2,3,4,5,6,7,8,9,10};
    int arrayB[18] = {20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
    int arrayC[8] = {-1,-2,-3,-4,-5,-6,-7,-8};

    std::cout << "\n\nBefore Movement\n";
    displayArray(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);

    dataMove(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);

    std::cout << "\n\nAfter Movement\n";
    displayArray(arrayA, arrayB, arrayC, sizeA, sizeB, sizeC);

    return 0;
}