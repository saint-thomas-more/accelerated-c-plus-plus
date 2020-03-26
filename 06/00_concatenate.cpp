// Use a library function to concatenate all elements of a vector<string>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> values = {"In", "the", "beginning", "was", "the", "word"};

    for(vector<string>::iterator i = values.begin(); i != values.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}