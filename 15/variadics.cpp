// Basic demonstration of variadic templates

#include <iostream>
#include <string>
#include <vector>

// Basic template
template<typename T>
T sum(T a, T b) {
    return a+b;
}

// Variadic base case and recursive case
template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename ... Args>
T adder(T first, Args ... args) {
    return first + adder(args ...);
}

// Basic generalisation
template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val initial_value) {
    Val v = initial_value;
    for(auto p = first; p != last; ++p) {
        v += *p;
    }
    return v;
}

int main() {
    std::cout << sum(5,6) << std::endl;
    std::cout << adder(1,2,3,4,5) << std::endl;

    std::vector<int> v = {1,2,3,4,5};
    auto sum = accumulate(v.begin(), v.end(), 0);
    std::cout << sum << std::endl;
    return 0;
}