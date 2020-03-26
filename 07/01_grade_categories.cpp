// Given a set of grades, group them into categories

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Randomly generate num grades between 0 and 100
vector<int> get_grades(int num) {
    vector<int> ret;
    for(int i = 0; i < num; i++) {
        ret.push_back(rand() % 101);
    }
    return ret;
}



int main() {
    // Get 30 grades
    vector<int> grades = get_grades(30);
    map<string, vector<int> > categories;

    for(auto const& g : grades) {
        string category_name = "" + to_string(g/10) + "0%" + " - " + to_string((g/10)+1) + "0%";
        categories[category_name].push_back(g);
    }

    for(auto const& c : categories) {
        cout << setw(12) << c.first << " || ";
        string values;
        for(auto const& v : c.second) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}