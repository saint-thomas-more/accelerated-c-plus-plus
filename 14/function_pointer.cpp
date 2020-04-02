// Demonstrate function pointers

#include <iostream>

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int perform_binary_operation(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

int main() {
    std::cout << perform_binary_operation(5, 10, add) << std::endl;
    return 0;
}

