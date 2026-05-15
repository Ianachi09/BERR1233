//  {10,20,30,40,50,60} array size 6
//   0  1  2  3  4  5
//      _     _     _
//
//  {10,60,30,20,50,40} array size 6
//   0  5  2  1  4  3
//      _     _     _



#include <iostream>

void dataMove(int array[], int size) {
    if (size%2 == 0) {
        size--;
    }

    int temp = array[size];
    for (int i=size; i>0; i-=2) {
        array[i] = array[i-2];
    }
    array[1] = temp;
}

int main() {
    int arrayA[6] = {10,20,30,40,50,60};
    int sizeA = 6;

    int arrayB[10] = {1,2,3,4,5,6,7,8,9,10};
    int sizeB = 10;

    std::cout << "Array A Before 6 Rotation" << std::endl;
    for(int i=0; i<sizeA; i++) {
        std::cout << "A[" << i << "]: " << arrayA[i] << std::endl;
    }
    std::cout << std::endl;

    for(int i=0; i<6; i++) {
        dataMove(arrayA, sizeA);
    }

    std::cout << "Array A After 6 Rotation" << std::endl;
    for(int i=0; i<sizeA; i++) {
        std::cout << "A[" << i << "]: " << arrayA[i] << std::endl;
    }
    std::cout << std::endl;


    std::cout << "Array B Before 6 Rotation" << std::endl;
    for(int i=0; i<sizeB; i++) {
        std::cout << "B[" << i << "]: " << arrayB[i] << std::endl;
    }
    std::cout << std::endl;

    for(int i=0; i<6; i++) {
        dataMove(arrayB, sizeB);
    }

    std::cout << "Array B After 6 Rotation" << std::endl;
    for(int i=0; i<sizeB; i++) {
        std::cout << "B[" << i << "]: " << arrayB[i] << std::endl;
    }
    std::cout << std::endl;
}