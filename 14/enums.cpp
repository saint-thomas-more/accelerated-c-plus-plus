// Demonstrate use of enumerated types

#include <iostream>

enum Colour {
    BLACK, WHITE, RED = 255
};

int main() {
    std::cout << Colour::BLACK << std::endl;
    std::cout << Colour::RED << std::endl;
}