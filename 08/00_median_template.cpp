// Write a template function to give the median value of any vector

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<class T> T median(vector<T> input) {
    typedef typename vector<T>::size_type size;
    size vector_size = input.size();
    if(vector_size == 0) {
        throw domain_error("Size cannot be 0");
    }
    sort(input.begin(), input.end());
    T median_value = input[vector_size/2];
    cout << median_value << endl;
    return median_value;
}

int main() {
    vector<double> double_median = {0.0, 3.0, 2.7, 1.4};
    vector<double> int_median = {3,2,1,4,5};

    median(double_median);
    median(int_median);
    return 0;
}