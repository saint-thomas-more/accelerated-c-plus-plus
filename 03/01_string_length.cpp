// Calculate the length of a string input

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    cout << "Enter a string: ";
    string input;
    cin >> input;
    cout << input << " is of length " << input.size() << endl;
    return 0;
}