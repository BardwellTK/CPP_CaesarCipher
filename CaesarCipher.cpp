#include <iostream>
#include <string>
#include <vector>
#include <sstream>
//using namespace std; will include this shortly

int main(int argc, char** argv) {
    //Get user input
    std::cout << "Caesar Cipher" << std::endl;
    std::cout << "=============" << std::endl;
    std::cout << "Enter plain text: ";
    std::string input;
    std::getline(std::cin,input);
    std::cout << "your input was: " << input << std::endl;
    return 0;
}