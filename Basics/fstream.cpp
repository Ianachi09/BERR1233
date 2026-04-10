#include <iostream>
#include <fstream> // for file handling

int main() {
    // Create an ofstream object to write to a file
    std::ofstream outFile("example.txt");
    
    // Check if the file was opened successfully
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1; // Exit with an error code
    }
    
    // Write some text to the file
    outFile << "Hello, this is a test file." << std::endl;
    outFile << "This file is created using C++ fstream." << std::endl;
    
    // Close the output file
    outFile.close();
    
    // Create an ifstream object to read from the file
    std::ifstream inFile("example.txt");
    
    // Check if the file was opened successfully
    if (!inFile) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1; // Exit with an error code
    }
    
    // Read and display the contents of the file
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl; // Print each line read from the file
    }
    
    // Close the input file
    inFile.close();
    
    return 0; // Exit with success code
}