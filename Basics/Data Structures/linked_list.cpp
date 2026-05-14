#include <iostream>

// Variables for Nodes
struct ListNode {
    int Value;
    ListNode *Next; // Addresses for next node
};

typedef ListNode* ListNodePointer; // Alias for "ListNode*" (makes the code readable)

class List {
    public: // Constructor & Deconstructor
    List();
    ~List();
    
    // Functions for Linked List
    void Display();
    //bool Search(int val);
    void Insert(int val);
    void InsertInOrder(int val); // Inserts in order (sequential)
    void Remove(int val);

    private:
    ListNodePointer Head; // Starting node
};

// Constuctor
List::List() {
    Head = NULL; // Set the starting node to null(empty)
}

// Deconstructor
List::~List() {
    ListNodePointer Temp; // Temp node to keep addresses of next node (this is needed to avoid memory leak)

    while(Head) { // While head still exists. . .
        Temp = Head -> Next; // Sends the address of head (next) to temp
        delete Head; // Delete the head
        Head = Temp; // Sends the address of next node to temp to continue the loop (until no value returned)
    }
}

// Display the values of every node
void List::Display() {
    ListNodePointer Temp = Head; // Temp node loop through the nodes (same address as head(first node))

    while(Temp) { // While temp is not null(empty). . .
        std::cout << Temp -> Value << std::endl; // Prints the values in temp
        Temp = Temp -> Next; // Get the address in current node and navigate to next node
    }
}

// Insertion to front
void List::Insert(int val) {
    ListNodePointer Temp = new ListNode; // Makes a new node then use temp to hold the address
    Temp -> Value = val; // Sends the value given to "value" in temp
    Temp -> Next = Head; // Set the "next" value to head(current first node)
    Head = Temp; // Set the temp node as the head(first node)
}

// Insertion in Order
void List::InsertInOrder(int val) {
    // 2 Temp nodes to keep the current position (head) and behind
    ListNodePointer current = Head; 
    ListNodePointer previous = NULL;

    ListNodePointer Temp = new ListNode; // Makes a new node then use temp to hold the address
    Temp -> Value = val; // Sends the value given to "value" in temp

    // Moving to between previous and current
    while ((current) && (current -> Value < val)) { // Limits the navigation to current and previous (since linked list is only one direction)
        previous = current;
        current =  current -> Next;
    }

    // Assigning temp to current node
    Temp -> Next = current;

    // Edge case, check if previous exists, if does point previous to temp, else set the temp node as the head(first node) 
    if (previous) {
        previous -> Next = Temp;
    } else {
        Head = Temp;
    }
}

// Removal
void List::Remove(int val) {
    // 2 Temp nodes to keep the current position (head) and behind
    ListNodePointer current = Head;
    ListNodePointer previous = NULL;

    while(current) {
        if (current -> Value == val) { // If target is found, 
            if (previous ==  NULL) { // Case if target is the head
                Head = current -> Next; // Isolating the head node 
                delete current; // Deleting the target node
                return;
            } else  {
                previous -> Next = current -> Next; // Send the address of next node (current) to previous node (Isolating the target node)
                delete current; // Deleting the target node
                return;
            }
        } else { // If not found, continue moving by setting previous to current and current to next node
            previous =  current;
            current = current -> Next;
        }

    }
}

int main() {
    List A;
    A.Insert(10);
    A.Insert(2);
    A.Insert(9);
    A.Insert(5);
    A.Insert(7);
    std::cout << "List A Before\n";
    A.Display();
    A.Remove(5);
    std::cout << "\nList A After\n";
    A.Display();

    List B;
    B.InsertInOrder(10);
    B.InsertInOrder(2);
    B.InsertInOrder(9);
    B.InsertInOrder(5);
    B.InsertInOrder(7);
    std::cout << "\nList B\n";
    B.Display();

    return 0;
}