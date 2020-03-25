// Calculate the quartiles of a set of numbers

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::sort;

void print(vector<int> const &input)
{
	for (auto const& i: input) {
		cout << i << " ";
	}
    cout << endl;
}

int main() {
    // Collect a set of values
    vector<int> values;
    int input;
    while (cin >> input) {
        values.push_back(input);
    }
    sort(values.begin(), values.end());
    cout << "The values entered are: ";
    print(values);

    // We assume that the values are large enough to be at least divisible by 4
    int quartileSize = values.size() / 4;
    for(int i = 0; i < 4; i ++) {
        cout << "Quartile " << i+1 << " is " << values[i * quartileSize] << endl;
    }
    return 0;
}