// Read a set of words as input and output a word count, as well as a count of words used

#include <iostream>
#include <vector>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std:: set;

using std::string;

int count_occurences(const set<string>& words, const string value) {
    int count = 0;
    for(auto const& w: words) {
        if(w == value) {
            count++;
        }
    }
    return count;
}

void print_occurences(vector<string> const &words)
{
    // First convert into a set
    set<string> set;
    for( unsigned i = 0; i < words.size(); ++i ) {
        set.insert(words[i]);
    }
	for (auto const& w: set) {
		cout << w << " occurs " << count_occurences(set, w) << " times" << endl;
	}
    cout << endl;
}

vector<string> read_words() {
    vector<string> words;

    string input;
    while(cin >> input) {
        words.push_back(input);
    }
    return words;
}

int count_words(const vector<string>& words) {
    return words.size();
}

int count_characters(const vector<string>& words) {
    int count = 0;
    for(auto const& w: words) {
        count += w.size();
    }
    return count;
}

int main() {
    vector<string> words = read_words();
    cout << "Total words = " << count_words(words) << endl;
    cout << "Total characters = " << count_characters(words) << endl;
    print_occurences(words);
    return 0;
}