// Write a template function to copy values from one iterator to another

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class In, class Out> Out copy_values(In begin, In end, Out dest) {
    while(begin != end) {
        *dest = *begin;
        dest++;
        begin++;
    }
    return dest;
}

int main() {
    vector<double> values = {0.0, 3.0, 2.7, 1.4};
    vector<double> copied_values = vector<double>(4);

    for(auto const& d: copied_values) {
        cout << d << " | ";
    }
    cout << endl;

    copy_values(values.begin(), values.end(), copied_values.begin());

    for(auto const& d: copied_values) {
        cout << d << " | ";
    }
    cout << endl;
    return 0;
}