#include <iostream>
using namespace std;
int main() {
    cout << "For loop example: " << endl; // Prints the message for the for loop example
    for(int i = 0; i < 5; i++) { //(typestart; condition; increment) A for loop that initializes i to 0, continues as long as i is less than 5, and increments i by 1 in each iteration
        cout << i << " "; // Prints the current value of i followed by a space
    }
    cout << endl;

    cout << "While loop example: " << endl; // Prints the message for the while loop example
    int j = 0; // Initializes j to 0
    while(j < 5) { // A while loop that continues as long as j is less than 5
        cout << j << " "; // Prints the current value of j followed by a space
        j++; // Increments j by 1
    }
    cout << endl;

    cout << "Do-while loop example: " << endl; // Prints the message for the do-while loop example
    int k = 0; // Initializes k to 0
    do { // A do-while loop that executes at least once and continues as long as k is less than 5
        cout << k << " "; // Prints the current value of k followed by a space
        k++; // Increments k by 1
    } while(k < 5);
    cout << endl;

    /* While loop and Do loop are very similar,
     but the only difference is that a do-while loop executes at least once, regardless of the condition */

    return 0;
}