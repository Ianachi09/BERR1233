#include <iostream>

// FIFO Queue

class Queue {
    public: // Constructor (w/ overloading) & Deconstructor
    Queue();
    Queue(int size);
    ~Queue();

    // Functions for Queue
    void Insert(int value);
    int Remove();
    int First();
    void Clear();
    void Display();

    private:
    // Variables Needed
    int* array; // * is for storing addresses
    int front;
    int rear;
    int count; // Keeps tract of current slot used, if count=size then the queue is full
    int size;
};

// Default Constructor
Queue::Queue() {
    size = 6;
    array = new int[size]; // "new" finds an empty addresses and brings back the first adress that it found

    front = 0;
    rear = size-1;
    count = 0;

    std::cout << "Default Queue Created\n";
}

// Overloaded Constructor (assigns the value if given value in the function)
Queue::Queue(int size) {
    this -> size = size;
    array = new int[size];

    front = 0;
    rear = size-1;
    count = 0;

    std::cout << "User-Defined Queue Created\n";
}

// Deconstrutor
Queue::~Queue() {
    delete [] array; // Deletes the values in array addresses
    std::cout << "Queue is destroyed.\n";
}

// Insertions
void Queue::Insert(int value) {
    if (count > size-1) { // Checks if queue is full by checking count and array size (-1 beacause arrays starts with index 0)
        std::cout << "Queue is full.\n";
        return;
    }

    if (rear==size-1) { // Checks if rear is on last index of array, then loops back to index 0, if not then increments as usual (Circular queue)
        rear = 0;
    } else {
        rear++;
    }

    // Assigns rear slot with value given and increments the count
    array[rear] = value;
    count++;
}

// Removals
int Queue::Remove() {
    if (count==0) { // Checks if queue is empty by comparing to 0
        std::cout << "Queue is empty.\n";
        return -1;
    }

    // Keeps the front value temporarily (since removal shifts the front value and count)
    int temp = array[front];

    if (front==size-1) { // Checks if front is on last index of array, then loops back to index 0, if not then increments as usual (Circular queue)
        front = 0;
    } else {
        front++;
    }

    // Decements the count and returns temp (front value)
    count--;
    return temp;
}

// Prints the front value
int Queue::First() {
    if (count == 0) { // Checks if queue is empty by comparing to 0, if not then returns the front value
        std::cout << "Queue is empty.\n";
        return -1;
    } else {
        return array[front];
    }
}

// Emptys the queue, setting the variables to default (no need to physically empty each addesses) 
void Queue::Clear() {
    front = 0;
    rear = size-1;
    count = 0;
}

// Displays the queue
void Queue::Display() {
    std::cout << "\n=========Display of Queue========= \n";
    if (count == 0) { // Checks if the queue is empty by comparing to 0
        std::cout << "Queue is empty\n";
    }
    for (int i=0; i<=count-1; i++) { // for loop to print every values in queue
        std::cout << "[" << i << "]: " << array[i] << std::endl;
    }
    std::cout << "==================================\n";
}

int main() {
    Queue A(6); // Constructs the queue (values are assigned)

    // Inserting values, then displays the queue
    A.Insert(10);
    A.Insert(20);
    A.Insert(30);
    A.Insert(40);
    A.Insert(90);
    A.Insert(70);

    A.Display();

    // Shows the front value for before and after removal
    std::cout << "Front: " << A.First() << std::endl;
    A.Remove();
    std::cout << "\nFront Atter Removing: " << A.First() << std::endl;

    // Clears the queue and prints the queue (will return empty)
    A.Clear();

    A.Display();

    return 0;
}