#include <iostream>

// function overloading: same function name but different parameters (number or type of parameters)
void function1() {
    std::cout << "This is function 1" << std::endl;
}

void function1(int x) {
    std::cout << "This is function 1 with parameter: " << x << std::endl;
}

// function passing: passing parameters to functions (by value, by reference, by pointer)
int function2(int x) {
    std::cout << "This is function 2 with parameter: " << x << std::endl;
    return x * 2;
}

void function3(int &y) {
    std::cout << "This is function 3 with parameter: " << y << std::endl;
}

int function4(int *z) {
    std::cout << "This is function 4 with parameter: " << *z << std::endl;
    return *z * 2;
}

int arrayfunction(int array[], int size) {
    std::cout << "This is an array function with size: " << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i << ": " << array[i] << std::endl;
    }
    return array[0]; // Just returning the first element for demonstration
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    std::cout <<"Array Function"<< std::endl;
    arrayfunction(arr, 5);

    std::cout <<"Function Overloading"<< std::endl;
    function1();
    function1(10);

    int result = function2(5);
    std::cout << "Result from function2 (pass by value): " << result << std::endl;

    int value = 10;
    function3(value);
    int *ptr = &value;

    int result2 = function4(ptr);
    std::cout << "Result from function4 (pass by pointer): " << result2 << std::endl;
    return 0;
}
