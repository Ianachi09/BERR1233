#include <iostream>

class Queue {
    public:
    Queue();
    Queue(int size);
    ~Queue();

    void Insert(int value);
    int Remove();
    int First();
    void Clear();
    void Display();

    private:
    int *array;
    int front;
    int rear;
    int count;
    int size;
};

Queue::Queue() {
    size = 6;
    array = new int[size];

    front = 0;
    rear = size-1;
    count = 0;

    std::cout << "Default Queue Created\n";
}

Queue::Queue(int size) {
    this -> size = size;
    array = new int[size];

    front = 0;
    rear = size-1;
    count = 0;

    std::cout << "User-Defined Queue Created\n";
}

Queue::~Queue() {
    delete [] array;
    std::cout << "Queue is destroyed.\n";
}

void Queue::Insert(int value) {
    if (count > size-1) {
        std::cout << "Queue is full.\n";
        return;
    }

    if (rear==size-1) {
        rear = 0;
    } else {
        rear++;
    }

    array[rear] = value;
    count++;
}

int Queue::Remove() {
    if (count==0) {
        std::cout << "Queue is empty.\n";
        return -1;
    }

    int temp = array[front];

    if (front==size-1) {
        front = 0;
    } else {
        front++;
    }
    count--;
    return temp;
}

int Queue::First() {
    if (count == 0) {
        std::cout << "Queue is empty.\n";
        return -1;
    } else {
        return array[front];
    }
}

void Queue::Clear() {
    front = 0;
    rear = size-1;
    count = 0;
}

void Queue::Display() {
    std::cout << "\n=========Display of Queue========= \n";
    if (count == 0) {
        std::cout << "Queue is empty\n";
    }
    for (int i=0; i<=count-1; i++) {
        std::cout << "[" << i << "]: " << array[i] << std::endl;
    }
    std::cout << "==================================\n";
}

int main() {
    Queue A(6);

    A.Insert(10);
    A.Insert(20);
    A.Insert(30);
    A.Insert(40);
    A.Insert(90);
    A.Insert(70);

    A.Display();

    std::cout << "Front: " << A.First() << std::endl;
    A.Remove();
    std::cout << "Front: " << A.First() << std::endl;

    A.Clear();

    A.Display();

    return 0;
}