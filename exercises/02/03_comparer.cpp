// Compare two numbers and output the larger

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "Please enter number a: ";
    int a, b;
    cin >> a;
    cout << "Please enter number b: ";
    cin >> b;

    if(a > b) {
        cout << "a is larger.";
    } else {
        if(a != b) {
            cout << "b is larger.";
        } else {
            cout << "a and b are the same.";
        }
    }
    cout << endl;
    return 0;
}