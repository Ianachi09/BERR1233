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
    size = 5;
    array = new int[size];
    currentPos = -1;
    std::cout << "Stack with size " << size << "(Default) created.\n";
}

Stack::Stack(int size) {
    this -> size = size;
    array = new int[size];
    currentPos = -1;
    std::cout << "Stack with size " << size << " created.\n";
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
    std::cout << "\n=========Display of Stack========= \n";
    if (currentPos == -1) {
        std::cout << "Stack is empty\n";
    }
    for(int i=0; i<=currentPos; i++) {
        std::cout << " A[" << i << "]: " << array[i] << std::endl;
    }
    std::cout << "==================================\n";
}
void Stack::Clear() {
    currentPos=-1;
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
