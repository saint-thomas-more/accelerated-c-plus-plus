#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;

    const std::string greeting = "Hello " + name;
    const std::string spaces(greeting.size(), ' ');
    const std::string frame = "* " + spaces + " *";

    const std::string stars(frame.size(), '*');

    std::cout << std:: endl;
    std::cout << stars << std::endl;
    std::cout << frame << std::endl;
    std::cout << greeting << std::endl;
    std::cout << frame << std::endl;
    std::cout << stars << std::endl;
    return 0;
}