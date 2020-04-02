// A class that replaces some of the std::String functionality

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Custom_String {

    public:
    // Create an empty String
    Custom_String() {

    }

    // Initialise with n copies of c
    Custom_String(size_t n, char c) {
        data = vector<char>(n, c);
    }

    template <class In> Custom_String(In begin, In end) {
        copy(begin, end, back_inserter(data));
    }

    Custom_String(const char* s) {
        copy(s, s + strlen(s), back_inserter(data));
    }

    vector<char>::iterator begin() {
        return data.begin();
    }

    vector<char>::iterator end() {
        return data.end();
    }

    size_t size() {
        return data.size();
    }

    void clear() {
        data.clear();
    }

    void push_back(char c) {
        return data.push_back(c);
    }

    // Overload operators
    char& operator[](size_t i) {
        return data[i];
    }

    Custom_String& operator+=(Custom_String& s) {
        copy(s.begin(), s.end(), back_inserter(data));
        return *this;
    }

    Custom_String& operator+=(const char* s) {
        copy(s, s + strlen(s), back_inserter(data));
        return *this;
    }

    operator int() {
        return (int)size();
    }

    private:
    vector<char> data;
};

// Non-member functions
istream& operator>>(istream& is, Custom_String& s) {
    s.clear();
    char c;
    while(is.get(c) && isspace(c)) {

    }
    if(is) {
        do {
            s.push_back(c);
        } while(is.get(c) && !isspace(c));
        if(is) {
            is.unget();
        }
    }
    return is;
}

ostream& operator<<(ostream& os, Custom_String s) {
    for(size_t i = 0; i < s.size(); i++) {
        os << s[i];
    }
    return os;
}

Custom_String operator+(Custom_String& a, Custom_String& b) {
    Custom_String output = a;
    output+= b;
    return output;
}

Custom_String operator+(char* a, Custom_String& b) {
    Custom_String output(a);
    output+= b;
    return output;
}


Custom_String operator+(Custom_String& a, const char* b) {
    Custom_String output(b);
    return a+=output;
}

int main() {
    Custom_String greeting("Hello");
    cout << greeting << endl;
    greeting += " there!";
    cout << greeting << endl;

    Custom_String new_greeting = (greeting + " John");
    cout << new_greeting << endl;

    Custom_String user_input;
    cin >> user_input;
    cout << user_input << endl;

    Custom_String ending = "End of input";
    cout << ending << endl;

    int as_int = ending;
    cout << as_int << endl;
    return 0 ;
}