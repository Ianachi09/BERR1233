#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cctype> // Added for the Ghost Buster (isalnum)
#include <algorithm>
#include <string>

struct saveData {
    std::string name;
    std::string difficulty;
    std::string attempt;
};

class Game {
private:
    bool isRunning;
    int target;

    enum highOrLow {
        Lower,
        Higher
    };
    enum difficulty {
        Easy = 51,
        Medium = 501,
        Hard = 2001,
        Extreme = 10001,
    };

    void saveScore(std::string name, int attempts, int diff) {
        std::ofstream file("leaderboard.txt", std::ios::app); // Open in append mode
        if (file.is_open()) {
            file << name << "|" << diffConverter(diff) << "|" << attempts << "\n";
            file.close();
        }
    }

    std::string cleanString(std::string str) {
        // 1. Destroy the invisible Windows UTF-8 BOM if it exists
        if (str.size() >= 3 && str.substr(0, 3) == "\xEF\xBB\xBF") {
            str.erase(0, 3);
        }
        // 2. Destroy any leading spaces, tabs, or carriage returns
        while (!str.empty() && str.front() > 0 && str.front() <= 32) {
            str.erase(0, 1);
        }
        // 3. Destroy any trailing spaces, tabs, or carriage returns
        while (!str.empty() && str.back() > 0 && str.back() <= 32) {
            str.pop_back();
        }
        return str;
    }

    void displayLeaderboard() {
        std::vector<saveData> leaderboard; 
        std::ifstream file("leaderboard.txt");
        
        // 1. Read and clean the data
        if (file.is_open()) {
            std::string tempName, tempDiff, tempAtt; 
            while (std::getline(file, tempName, '|') &&
                   std::getline(file, tempDiff, '|') &&
                   std::getline(file, tempAtt, '\n')) {
                
                tempName = cleanString(tempName);
                tempDiff = cleanString(tempDiff);
                tempAtt  = cleanString(tempAtt);
                
                if (!tempName.empty()) { 
                    leaderboard.push_back({tempName, tempDiff, tempAtt}); 
                }
            }
            file.close(); 
        }

        // If the file is totally empty, stop here and return to main menu
        if (leaderboard.empty()) {
            system("cls");
            std::cout << "No scores recorded yet!\n\n";
            return; 
        }
        
        // Start the target difficulty as "All"
        std::string diffFilter = "All";

        // LEADERBOARD SUB-MENU LOOP
        while (true) {
            // 2. Create the filtered list based on current diffFilter
            std::vector<saveData> filteredBoard;
            for (size_t i = 0; i < leaderboard.size(); i++) {
                if (diffFilter == "All" || leaderboard[i].difficulty == diffFilter) {
                    filteredBoard.push_back(leaderboard[i]);
                }
            }

            // 3. Sort the filtered list by lowest attempts
            std::sort(filteredBoard.begin(), filteredBoard.end(), [](const saveData& a, const saveData& b) {
                return std::stoi(a.attempt) < std::stoi(b.attempt);
            });
            
            // 4. Display the board
            system("cls");
            std::cout << "========================================================\n";
            std::cout << "                 Leaderboard (" << diffFilter << ")                 \n";
            std::cout << "========================================================\n";
            
            std::cout << std::left
                      << std::setw(8)  << "Rank"
                      << std::setw(15) << "Name" 
                      << std::setw(15) << "Difficulty" 
                      << std::setw(10) << "Attempts\n";
            std::cout << "-------------------------------------------------------\n";

            if (filteredBoard.empty()) {
                std::cout << "No scores recorded for this difficulty yet!\n";
            } else {
                for (size_t i = 0; i < filteredBoard.size(); i++) {
                    std::string rankStr = "[" + std::to_string(i + 1) + "]";
                    std::cout << std::left
                              << std::setw(8)  << rankStr
                              << std::setw(15) << filteredBoard[i].name 
                              << std::setw(15) << filteredBoard[i].difficulty 
                              << std::setw(10) << filteredBoard[i].attempt << "\n";
                }
            }
            std::cout << "========================================================\n\n";

            // Provide filter options at the bottom
            std::cout << "Filter Options:\n";
            std::cout << "[1] All Difficulties\n";
            std::cout << "[2] Easy Only\n";
            std::cout << "[3] Medium Only\n";
            std::cout << "[4] Hard Only\n";
            std::cout << "[5] Extreme Only\n";
            std::cout << "[0] Return to Main Menu\n";
            std::cout << "Choice: ";

            int filterChoice;
            std::cin >> filterChoice;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue; // Ignore bad input and just reprint the current board
            }

            if (filterChoice == 0) {
                system("cls"); // Clean the screen before leaving
                break;         // Exit the leaderboard loop and go back to main menu
            }

            switch (filterChoice) {
                case 1: diffFilter = "All"; break;
                case 2: diffFilter = "Easy"; break;
                case 3: diffFilter = "Medium"; break;
                case 4: diffFilter = "Hard"; break;
                case 5: diffFilter = "Extreme"; break;
                default: break; // If they type an invalid number, do nothing and reprint
            }
        }
    }

    int rng(int range) {
        return rand() % range;
    }

    std::string diffConverter(int diffEnum) {
        switch (diffEnum)  {
            case Easy: return "Easy";
            case Medium: return "Medium";
            case Hard: return "Hard";
            case Extreme: return "Extreme";
            default: return "Unknown";
        }
    }

    void dialogue(highOrLow result) {
        int choice = rng(101);
        switch (result) {
            case Lower:
                if (choice <= 25) {
                    std::cout << "Too low! Try a bit higher.\n";
                } else if (choice <= 75) {
                    std::cout << "Still too low.\n";
                } else {
                    std::cout << "Nope, lower than the target.\n";
                }
                break;

            case Higher:
                if (choice <= 25) {
                    std::cout << "Too high! Try a bit lower.\n";
                } else if (choice <= 75) {
                    std::cout << "Still too high.\n";
                } else {
                    std::cout << "Nope, higher than the target.\n";
                }
                break;
        }
    }

    void round() {
        system("cls");
        int guess = -1;
        int attempt = 0;
        int lowerBound = 0; 
        int diff = -1;
        
        // Trap the user until they pick a valid difficulty
        while (true) {
            std::cout << "Choose your difficulty: \n";
            std::cout << "[1] Easy (0-50)\n";
            std::cout << "[2] Medium (0-500)\n";
            std::cout << "[3] Hard (0-2000)\n";
            std::cout << "[4] Extreme (0-10000)\n";
            std::cout << "Choice: ";

            std::cin >> diff;
            
            // Check for valid input
            if (std::cin.fail() || diff < 1 || diff > 4) { 
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                system("cls");
                std::cout << "Invalid choice. Please select 1, 2, 3, or 4.\n\n";
            } else {
                break; // Valid! Break out of the loop.
            }
        }
        
        switch (diff) {
            case 1: diff = Easy; break;
            case 2: diff = Medium; break;
            case 3: diff = Hard; break;
            case 4: diff = Extreme; break;
        }
        
        target = rng(diff);
        
        std::string name;
        int upperBound = diff - 1;
        
        // Trap the user until they pick a valid name
        while (true) {
            std::cout << "Enter your name (8 Characters max): ";
            std::cin >> name;

            if (std::cin.fail()) { 
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Illegal name. Please try again.\n\n";
            } else if (name.length() > 8) {
                // Clear any leftover words they might have typed
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Exceeded 8 characters. Please try again.\n\n";
            } else {
                // Clear the stream for safety and move on
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        while (guess != target) {
            std::cout << "\nAttempt " << attempt << " \tLower: " << lowerBound << " \tUpper: " << upperBound << std::endl;
            std::cout << "=========================================\n";
            std::cout << "Guess a number: ";

            std::cin >> guess;

            if (std::cin.fail()) { 
                system("cls");
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Invalid input. Please enter a number.\n";
                guess = -1;
                continue; 
            }

            if (guess < 0 || guess > upperBound) {
                system("cls");
                std::cout << "Out of bounds! Please guess within the game limits.\n";
                continue;
            }

            attempt++; // Increment attempt ONLY after valid input
            system("cls");
            
            if (guess < target) {
                dialogue(Lower);
                // Prevent bounds from accidentally expanding if user guesses poorly
                if (guess > lowerBound) lowerBound = guess; 
            } else if (guess > target) {
                dialogue(Higher);
                // Prevent bounds from accidentally expanding
                if (guess < upperBound) upperBound = guess; 
            } else {
                system("cls");
                std::cout << "\nCongrats! The number is " << target << "!\n";
                std::cout << "Attempts taken:  " << attempt << std::endl;
                saveScore(name, attempt, diff);
            }
        }
    }

public:
    Game() {
        isRunning = true;
        srand(time(0)); 
    }

    void run() {
        while (isRunning) {
            std::cout << "=================================\n";
            std::cout << "       Welcome to the Game       \n";
            std::cout << "=================================\n";
            std::cout << "[1] Play\n";
            std::cout << "[2] View Leaderboard\n";
            std::cout << "[0] Exit Game\n";
            std::cout << "Choice: ";

            int choice;
            std::cin >> choice;

            if (std::cin.fail()) { 
                std::cin.clear();  
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                system("cls");
                std::cout << "Invalid choice. Please try again.\n\n";
                continue;
            }

            switch (choice) {
                case 1:
                    round();
                    break;
                case 2:
                    displayLeaderboard();
                    break;
                case 0:
                    std::cout << "\nExiting game. . .\n";
                    isRunning = false;
                    break;          
                default:
                    system("cls");
                    std::cout << "Please select 1, 2 or 0.\n\n";
                    break;
            }
        }   
    }
};

int main() {
    Game myGame;
    myGame.run();
    
    return 0;
}