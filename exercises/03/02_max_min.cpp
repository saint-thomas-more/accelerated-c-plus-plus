// Output the maximum and minimum values of a set of integers

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

int main() {
    cout << "Enter a set of integers: ";
    // Collect a set of values
    vector<int> values;
    int input;
    while (cin >> input) {
        values.push_back(input);
    }
    sort(values.begin(), values.end());
    cout << endl << "Smallest value is: " << values[0] << endl;
    cout << "Largest value is: " << values[values.size() - 1] << endl;

    return 0;
}