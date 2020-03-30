#include <iostream>

void perform_operation(int a, int b, void (*func) (const int x, const int y)) {
    func(a, b);
}

void add(int a, int b) {
    std::cout << (a+b) << std::endl;;
}

void multiply(int a, int b) {
    std::cout << (a*b) << std::endl;
}

int main() {
    void (*add_func)(int, int) = &add;
    void (*mult_func)(int, int) = &multiply;

    perform_operation(5, 6, add_func); 
    perform_operation(5, 6, mult_func);
}