#include <iostream>

int* get_x() {
    static int x = 5;
    return &x;
}

int main() {
    std::cout << get_x() << std::endl;
}