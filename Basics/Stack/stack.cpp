#include <iostream>

class Stack {
    protected:
    int *array;
    int size;
    int currentPos;

    public:
    Stack();
    Stack(int size);
    ~Stack();

    void Push(int value);
    int Pop();
    int Top();
    void Clear();
    void Display();
};

Stack::Stack() {
    int size = 5;
    array = new int[size];
    currentPos = -1;
    std::cout << "Stack with size " << size << " Created.\n";
}

Stack::Stack(int size) {
    this -> size = size;
    array = new int[size];
    currentPos = -1;
    std::cout << "Stack with size " << size << " Created.\n";
}

Stack::~Stack() {
    delete [] array;
    std::cout << "\nStack Deleted.";
}

void Stack::Push(int value) {
    if (currentPos < size-1) {
        currentPos+=1;
        array[currentPos] = value;
    } else {
        std::cout << "Stack Overflow!!\n";
    }
}

int Stack::Pop() {
    int result;

    if(currentPos >= 0) {
        result = array[currentPos];
        currentPos-=1;

        return result;
    } else {
        std::cout << "Stack Underflow!!\n";
        return -1;
    }

}

int Stack::Top() {
    int result;

    if (currentPos >= 0) {
        result=array[currentPos];

        return result;
    } else {
        std::cout << "Stack Underflow!!\n";
        return -1;
    }
}

void Stack::Display() {
    std::cout << "=========Display of Stack========= \n";
    for(int i=0; i<size; i++) {
        std::cout << " A[" << i << "]: " << array[i] << std::endl;
    }
}
void Stack::Clear() {
    currentPos=-1;
}

int main() {


    return 0;
}
