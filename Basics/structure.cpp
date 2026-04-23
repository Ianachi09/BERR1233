#include <iostream>
#include <string>

class Student {
    protected:

    struct Details {
        std::string name;
        std::string studentID;
        std::string faculty;
        int year;

        Details(std::string name, std::string studentID, std::string faculty, int year) : name(name), studentID(studentID), faculty(faculty), year(year) {
            std::cout << "Structure Initialized\n";
        }
    };

    Details StudentInfo;

    public:
    Student(std::string name, std::string studentID, std::string faculty, int year) : StudentInfo(name, studentID, faculty, year) {
        std::cout << "Student " << name << " Created\n";
    }
};

int main() {
    Student student1("Aiman","B122510564","FTKEK",2);
}
