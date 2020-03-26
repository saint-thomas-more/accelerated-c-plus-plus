// Count the number of words using a map

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    map<string, int> occurences;

    while(cin >> s) {
        occurences[s]++;
    }

    for(map<string, int>::iterator i = occurences.begin(); i != occurences.end(); i++ ){
        cout << i->first << " = " << i ->second << endl;
    }
    return 0;
}