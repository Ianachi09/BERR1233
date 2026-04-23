#include <iostream>

// Factorial functions
int factorial(int step) {

    // Special case, 1! or 0! is 1
    if (step <= 1) {
        return 1;
    }

    // Return the result, but calls the function again but with one step below
    // (function cannot finish until it recieves 1(or 0), then it returns in chain until first calls of function)
    return step * factorial(step-1);
}

/*
int fibonacci(int step) {
    while (step >= 0) {
    if (step == 1 || step == 2) {
        return 1;
    } else if (step == 0) {
        return 0;
    }


}
    return fibon


}
*/

int main() {
    int a = 5;

    std::cout << "Factorial of " << a << " is: " << factorial(a);
}
