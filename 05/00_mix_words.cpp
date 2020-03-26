// Take a set of space-separated strings and return them mixed

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Take a string and split by whitespace
vector<string> split(string input) {
    vector<string> output;
    typedef string::size_type string_size;
    
    string_size start = 0;
    
    while(start != input.size()) {
        // Find the start of the word
        while(start != input.size() && isspace(input[start])) {
            start++;
        }
        // Find the end of the word
        string_size end = start;
        while(end != input.size() && !isspace(input[end])) {
            end++;
        }
        output.push_back(input.substr(start, end-start));
        start = end;
    }
    return output;
}

vector<string> mix(vector<string> input) {
    int num_swaps = rand() % input.size();
    for(int i = 0; i < num_swaps; i++) {
        int a = rand() % input.size();
        int b = rand() % input.size();
        string original_a = input[a];
        input[a] = input[b];
        input[b] = original_a;
    }
    return input;
}

int main() {
    cout << "Enter a set of space-separated strings: " << endl;
    string input;    
    getline(cin, input);
    vector<string> words = mix(split(input));
    for(auto const& i : words) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}