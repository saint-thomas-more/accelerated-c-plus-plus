// Examples of implicit and explicit casting

#include <iostream>

using namespace std;

int main() {
    // Implicit casting
    int a = 5;
    double x = a;
    cout << "Integer a is " << a << " and the double is " << x << endl;

    double y = 10.9;
    int b = y;
    cout << "Double y is " << y << " and the integer is " << b << endl;

    // Explicit
    float f = {static_cast<float>(a) / static_cast<float>(b)};
    cout << "a / b is " << f << endl;
}