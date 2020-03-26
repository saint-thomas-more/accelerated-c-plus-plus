#include <string>
#include <vector>
#include "split.h"

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