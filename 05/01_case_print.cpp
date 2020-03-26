// Writes out all uppercase words, followed by all lowercase words

#include <iostream>
#include <vector>
#include "split.h"

using namespace std;

bool is_upper_case(char input) {
    return input < 97;
}

void print_words(vector<string> input) {
    for(auto const& i : input) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter a set of space-separated strings: " << endl;
    string input;    
    getline(cin, input);
    vector<string> words = split(input);
    vector<string> upper_words;
    vector<string> lower_words;

    for(auto const& i : words) {
        if(is_upper_case(i[0])) {
            upper_words.push_back(i);
        } else {
            lower_words.push_back(i);
        }
    }
    print_words(upper_words);
    print_words(lower_words);
    return 0;
}