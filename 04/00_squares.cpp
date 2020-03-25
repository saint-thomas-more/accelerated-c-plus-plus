// Calculate the squares of int values up to 10 using setw and two columns

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;

int main() {
    cout << "||  n  || n^2 ||" << endl;
    for(int i = 1; i <= 10; i++) {
        cout << setw(5) << i << setw(7) << i*i << endl;
    }
    return 0;
} 

