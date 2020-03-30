// Basic pointer PoC

#include <iostream>

using namespace  std;

int main() {
    int x = 15;
    cout << "x is " << x << endl;

    int *p = &x;
    cout << "x is at address " << p << endl;
    *p = 10;
    cout << "x is now " << x << endl;
    return 0;
}