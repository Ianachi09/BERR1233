#include <iostream>

struct TreeNode {
    int value; // Data 
    TreeNode* Left; // Addresses for left child
    TreeNode* Right; // Addresses for right child
};

typedef TreeNode* TreeNodePointer; // Alias for "TreeNode*" (makes the code readable), TreeNode* keeps track of addresses

class Tree {
    public:
    Tree();
    ~Tree();
    // "Main function", only calls the private (helper) functions and passes them the variable
    void Display();
    void Insert(int Val);
    bool Search(int Val);

    // Helper functions, all the heavyliftings are by them
    private:
    TreeNodePointer Root;
    void InsertTree (TreeNodePointer& Root, int Val);
    void DisplayTree (TreeNodePointer Root, int choice);
    bool SearchTree (TreeNodePointer Root, int Val);
    void DeleteCompleteTree (TreeNodePointer Root);
};

// Constructor
Tree::Tree(){
    Root = NULL; // Sets to NULL since its empty the first timex
}

// Deconstructor
Tree::~Tree(){
    DeleteCompleteTree(Root); // Calls the helper function to delete the whole  tree
}

// Deletion Function
void Tree::DeleteCompleteTree(TreeNodePointer Root) {
    if (Root != NULL) {
        // Deletes the left and right childs first. . .
        DeleteCompleteTree(Root -> Left); 
        DeleteCompleteTree(Root -> Right);
        // Then deletes the parent
        delete Root;
    }
}

// Main Insert
void Tree::Insert(int Val) {
    InsertTree(Root, Val); // Calls the helper function and passes the root addresses and value to insert
}

// Insert Function
void Tree::InsertTree(TreeNodePointer& Root, int Val) {
    // If node is empty, make it into a new node then put the data in
    if (Root == NULL) {
        Root = new TreeNode;
        Root -> Left = NULL;
        Root -> Right = NULL;
        Root -> value = Val;
        return;
    }

    // Case for duplication, cancels the operation
    if (Val == Root-> value) {
        return;
    }

    // Check if numbers in current node is bigger or less.
    if (Val < Root -> value) { // If less, then move to the left
        InsertTree(Root -> Left,Val);
    } else { // else, move to the right
        InsertTree(Root -> Right,Val);
    }
}

// Main Display
void Tree::Display() {
    int choice;
    std::cout << "What order to show?\n";
    std::cout << "[1] Pre-Order\n";
    std::cout << "[2] In-Order\n";
    std::cout << "[3] Post-Order\n";
    std::cin >> choice;

    DisplayTree(Root, choice);
}

// Display Function
void Tree::DisplayTree(TreeNodePointer Root, int choice) {
    switch (choice) {
        case 1: // Pre-Order
        if (Root != NULL) { // If node is not empty. . .
            std::cout << Root -> value << " "; // Then print the value
            DisplayTree(Root -> Left, choice); // Move to the left node (Recursion until leftmost node)
            DisplayTree(Root -> Right, choice);  // Move to the right (Repeats the previous recursions)
        }
        break;

        case 2: // In-Order
        if (Root != NULL) { // If node is not empty. . .
            DisplayTree(Root -> Left, choice); // Move to the left node (Recursion until leftmost node)
            std::cout << Root -> value << " "; // Then print the value
            DisplayTree(Root -> Right, choice);  // Move to the right (Repeats the previous recursions)
        }
        break;

        case 3: // Post-Order
        if (Root != NULL) { // If node is not empty. . .
            DisplayTree(Root -> Left, choice); // Move to the left node (Recursion until leftmost node)
            DisplayTree(Root -> Right, choice);  // Move to the right (Repeats the previous recursions)
            std::cout << Root -> value << " "; // Then print the value
        }
        break;
        
        default:
        break;

    }
}


// Main Search
bool Tree::Search(int Val) {
    return SearchTree(Root, Val);
}

// Search Function
bool Tree::SearchTree(TreeNodePointer Root, int Val) {
    if (Root==NULL) { // If the number doesn't exist. . .
        return false;
    }

    if (Root -> value == Val) { // If it matches the number
        return true;
    }

    // Traversal Sections
    if (Val < Root -> value) { // Move to left node if target is smaller than current page
        return SearchTree(Root -> Left, Val);
    }

    return SearchTree(Root -> Right, Val); // Else, move to right node
}


int main () {
    /* Tree T1;
    int key;

    T1.Insert(5);
    T1.Insert(15);
    T1.Insert(40);
    T1.Insert(30);
    T1.Insert(84);
    T1.Insert(51);
    T1.Insert(32);
    T1.Insert(18);

    T1.Display();

    // Searching Sections
    std::cout << "Enter the value to search: " << std::endl;
    std::cin >> key;

    if (T1.Search(key)) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    std::cout << "==============================================" << std::endl;

    Tree T2;
    int i;

    for (i=1; i<50; i++) {
        T2.Insert(i);
    }

    T2.Display(); */

    Tree AB;
    AB.Insert(15);
    AB.Insert(30);
    AB.Insert(25);
    AB.Insert(5);
    AB.Insert(12);
    AB.Insert(7);
    AB.Insert(1);

    AB.Display();
}