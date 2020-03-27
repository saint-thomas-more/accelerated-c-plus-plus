// Write a template function to determine whether two vectors are equal

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T> bool equal(vector<T> a, vector<T> b) {
    typedef typename vector<T>::iterator iter;
    iter iter_a = a.begin();
    iter iter_b = b.begin();

    if(a.size() != b.size()) {
        return false;
    }

    while(iter_a != a.end()) {
        if(*iter_a != *iter_b) {
            return false;
        }
        iter_a++;
        iter_b++;
    }

    return true;
}

int main() {
    vector<double> a = {0.0, 3.0, 2.7, 1.4};
    vector<double> b = {1, 2, 3, 4};

    vector<int> c = {1,2,3};
    vector<int> d = {1,2,3};

    cout << "a == b -> " << equal(a, b) << endl;
    cout << "c == d -> " << equal(c, d) << endl;
    return 0;
}