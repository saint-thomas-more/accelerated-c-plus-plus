// Sorts a set of grades into a pass and fail list

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_fail(int value) {
    return value < 40;
}

int main() {
    vector<int> grades = {99, 43, 65, 12, 24, 80, 38};
    vector<int> pass_grades;

    remove_copy_if(grades.begin(), grades.end(), back_inserter(pass_grades), is_fail);

    cout << "Passing scores: | ";
    for(auto const& i : pass_grades) {
        cout << i << " | ";
    }
    cout << endl;
    return 0;
}