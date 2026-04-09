#include <iostream>
#include <vector>

class Parent {
    private:
        int privateVar; // Private member variable, accessible only within the Parent class
    protected:
        int protectedVar; // Protected member variable, accessible within the Parent class and its derived classes
    public:
        int publicVar; // Public member variable, accessible from anywhere

        // Parameterized Constructor (Setup with specific starting values)
        Parent(int priv = 0, int prot = 0, int pub = 0) {
            privateVar = priv;
            protectedVar = prot;
            publicVar = pub;
            std::cout << "\nParent Blueprint Built.\n";
        }

        // Virtual Destructor to ensure proper cleanup of derived class objects through base class pointers
        virtual ~Parent() {
            std::cout << "\nParent Blueprint Destroyed.\n";
        }

        // Virtual function, Parent sets the function, but Child can override it (Polymorphism)
        virtual void display() {
            std::cout << "\n--- Parent's View ---" << std::endl;
            std::cout << "Private Variable: " << privateVar << std::endl; // Accessible in Parent class, but not in Child class (will use getter in Child)
            std::cout << "Protected Variable: " << protectedVar << std::endl; // Accessible in Child class
            std::cout << "Public Variable: " << publicVar << std::endl; // Accessible in Child class
        }

        // Setter 
        void setPrivateVar(int value) { // Public member function to set the value of privateVar
            privateVar = value;
        }

        // Getter   
        int getPrivateVar() { // Public member function to get the value of privateVar
            return privateVar;
        }
};

class Child : public Parent {
    private:
        int childVariable; // Additional private member variable for Child class
    
    public:
    // Child Constructor passing instructions to the Parent, parent handles the setup of the member variables, and child can also have its own constructor for additional setup
    Child(int priv, int prot, int pub, int childVar) : Parent(priv, prot, pub) {
        childVariable = childVar; // Additional member variable for Child class
        std::cout << "\nChild Blueprint Built.\n";
    }

    // Virtual Child Destructor to ensure proper cleanup of Child objects when deleted through Parent pointers
    ~Child() override {
            std::cout << "\nChild Blueprint Destroyed.\n";
        }

    // Function to alter protected variable (since main cannot access it directly)
    void alterProtectedVar(int newValue) {
            // Notice: No setter used here! We touch the variable directly.
            protectedVar = newValue; 
        }

    void display() override { // Public member function to display the values of member variables
        std::cout << "\n--- Child's View ---" << std::endl;
        std::cout << "Private Variable: " << getPrivateVar() << std::endl; // Accessible in Child class through getter
        std::cout << "Protected Variable: " << protectedVar << std::endl; // Accessible in Child class
        std::cout << "Public Variable: " << publicVar << std::endl; // Accessible in Child class
        std::cout << "Child Variable: " << childVariable << std::endl; // Accessible in Child class
    }
};

// Demonstrating a single Parent-Child relationship, where we create a Child object and call both the Parent's and Child's display functions to show the values of the member variables. We also demonstrate changing the values of the variables and how it affects both views.
void demonstrateSingleObject() {
    std::cout << "\n================= SINGLE OBJECT DEMO =================" << std::endl;
    
    Child myObject(10, 20, 30, 40);

    myObject.Parent::display(); 
    myObject.display(); 

    myObject.setPrivateVar(99); 
    myObject.publicVar = 88;    
    myObject.alterProtectedVar(77);

    std::cout << "\n------------------- After Changes ---------------------" << std::endl;
    myObject.Parent::display(); 
    myObject.display(); 
}


// Demonstrating Polymorphism with a vector of Parent pointers, which can point to both Parent and Child objects. When we call display() on each member, the correct version (Parent or Child) is called based on the actual object type, showcasing polymorphism.
void childInParent() {
    std::cout << "\n================ POLYMORPHISM DEMO =================" << std::endl;
    
    std::vector<Parent*> familyTree;

    familyTree.push_back(new Parent(1, 2, 3));
    familyTree.push_back(new Child(10, 20, 30, 40));
    familyTree.push_back(new Parent(5, 5, 5));
    familyTree.push_back(new Child(100, 200, 300, 400));

    for (Parent* member : familyTree) {
        member->display(); 
    }

    for (Parent* member : familyTree) {
        delete member;
    }
}


int main() {
    demonstrateSingleObject(); 
    
    childInParent(); 

    return 0;
}
