#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;


int main() {
    cout << "Please enter your name: ";
    string name;
    cin >> name;

    const string greeting = "Hello " + name;
    const string spaces(greeting.size(), ' ');
    const string frame = "* " + spaces + " *";

    const string stars(frame.size(), '*');

    cout << std:: endl;
    cout << stars << std::endl;
    cout << frame << std::endl;
    cout << greeting << std::endl;
    cout << frame << std::endl;
    cout << stars << std::endl;
    return 0;
}