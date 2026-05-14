#include <iostream>

// LIFO Stack

class Stack {
    
    public: // Constructor (w/ overloading) & Deconstructor
    Stack();
    Stack(int size);
    ~Stack();
    
    // Functions for Stack
    void Push(int value);
    int Pop();
    int Top();
    void Clear();
    void Display();

    protected:
    int *array; // * is for storing addresses
    int size;
    int currentPos; // Current Position
};

// Default Constructor
Stack::Stack() {
    size = 5;
    array = new int[size]; // "new" finds an empty addresses and brings back the first adress that it found
    currentPos = -1; // Set to -1 as there is no value (-1 is nonexistent in indexes)
    std::cout << "Stack with size " << size << "(Default) created.\n";
}

// Overloaded Constructor (assigns the value if given value in the function)
Stack::Stack(int size) {
    this -> size = size;
    array = new int[size];
    currentPos = -1;
    std::cout << "Stack with size " << size << " created.\n";
}

// Deconstrutor
Stack::~Stack() {
    delete [] array; // Deletes the values in array addresses
    std::cout << "\nStack Deleted.";
}

// Insertion
void Stack::Push(int value) {
    if (currentPos < size-1) { // Checks if its empty (size-1 because index starts with 0), then increments current position by 1 and assigns the value to the slot
        currentPos+=1;
        array[currentPos] = value;
    } else { // Else (array is full) sends an error message for stack overflow (no way to assign the values into full memory)
        std::cout << "Stack Overflow!!\n";
    }
}

// Removal
int Stack::Pop() {
    int result;

    if(currentPos >= 0) { // Checks if array have any data
        // Pass the value to result, decrements current position and returns the result
        result = array[currentPos];
        currentPos-=1;
        return result;
    } else { // Else (array is empty) sends an error message for stack underflow (no way to get values from empty memory)
        std::cout << "Stack Underflow!!\n";
        return -1;
    }

}

// View most recents data
int Stack::Top() {
    int result;

    if (currentPos >= 0) { // Checks if array have any data, then pass the value to result and returns it
        result=array[currentPos];
        return result;
    } else { // Else (array is empty) sends an error message for stack underflow (no way to get values from empty memory)
        std::cout << "Stack Underflow!!\n";
        return -1;
    }
}

void Stack::Display() {
    std::cout << "\n=========Display of Stack========= \n";
    if (currentPos == -1) { // Checks if array is empty by comparing current position to -1
        std::cout << "Stack is empty\n";
    }
    for(int i=0; i<=currentPos; i++) { // for loop to print all the values in array
        std::cout << " A[" << i << "]: " << array[i] << std::endl;
    }
    std::cout << "==================================\n";
}

// Clear array
void Stack::Clear() {
    currentPos=-1; // Set the current position to -1 (No need to delete each slot as it will be overwritten if we enter new data)
}

int main() {
    //int size = 6;
    Stack stack1;

    stack1.Push(10);
    stack1.Push(20);
    stack1.Push(30);
    stack1.Push(40);
    stack1.Push(70);
    //stack1.Push(80);
    
    stack1.Display();

    std::cout << stack1.Top() << std::endl;
    std::cout << stack1.Pop() << std::endl;
    std::cout << stack1.Top() << std::endl;

    
    stack1.Display();
    stack1.Clear();
    stack1.Display();
    return 0;
}
