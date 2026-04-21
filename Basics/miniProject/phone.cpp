#include <cstdlib>
#include <iostream>
#include <string>
//#include <random>
#include <ctime>
#include <unistd.h>

class Phone {
    protected:
    int ramSize;
    std::string processor;
    float screenSize;
    std::string camera;
    std::string OSVersion;

    public:
    Phone(int ramSize, std::string processor, float screenSize, std::string camera, std::string OSVersion);
    ~Phone();

    void GetSpec();
    //void Power();
    void Call();
    void Text();
    void Photo();
    void Video();
};

Phone::Phone(int ramSize, std::string processor, float screenSize, std::string camera, std::string OSVersion) {
    this -> ramSize = ramSize;
    this -> processor = processor;
    this -> screenSize = screenSize;
    this -> camera = camera;
    this -> OSVersion = OSVersion;
    std::cout << "Phone is created." << std::endl;
}

Phone::~Phone() {
    std::cout << "Phone is Destroyed." << std::endl;
}

void Phone::GetSpec() {
    std::cout << "\n===============Specification===============\n";
    std::cout << "RAM Size: " << ramSize << std::endl;
    std::cout << "Processor: " << processor << std::endl;
    std::cout << "Screen Size: " << screenSize << std::endl;
    std::cout << "Camera: " << camera << std::endl;
    std::cout << "OS Version: " << OSVersion << std::endl;
}

void Phone::Call() {
    std::cout << std::endl;
    std::cout << "Calling. . ." << std::endl;
    std::cout << "Connected." << std::endl;
    std::cout << "Hello. Anyone There?" << std::endl;
    std::cout << "Hangs Up." << std::endl;
}

void Phone::Text() {
    std::cout << std::endl;
    std::cout << "Texting. . ." << std::endl;
    std::cout << "You: Hello Bob!!!" << std::endl;
    std::cout << "Bob: Hi!!!\n" << std::endl;
    std::cout << "===============After a while of texting. . .===============\n" << std::endl;
    std::cout << "You: Alright I got to go now." << std::endl;
    std::cout << "Bob: Talk to you later!!" << std::endl;
}

void Phone::Photo() {
    //system("clear");
    std::cout << std::endl;
    std::cout << "Taking Pictures. . ." << std::endl;
    int quality = std::rand() % 2 + 1;
    switch (quality) {
        case 1:
        std::cout << "Nice picture!" << std::endl;
        break;

        case 2:
        std::cout << "Aww, the picture is blurry." << std::endl;
        break;

        default:
        break;
    }
}

void Phone::Video() {
    //system("clear");
    std::cout << std::endl;
    std::cout << "Recording Video. . ." << std::endl;
    int quality = std::rand() % 2 + 1;
    switch (quality) {
        case 1:
        std::cout << "Nice footage!" << std::endl;
        break;

        case 2:
        std::cout << "Aww, the video is blurry." << std::endl;
        break;

        default:
        break;
    }
}


int main() {
    std::srand(std::time(0));
    Phone FirstPhone(1600,"Snapdragon",6.3,"Leica","One UI 8.5");

    FirstPhone.GetSpec();
    FirstPhone.Call();
    FirstPhone.Text();
    FirstPhone.Photo();
    FirstPhone.Video();
}
