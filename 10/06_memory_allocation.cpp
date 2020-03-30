#include <iostream>
#include <string>

using namespace std;

// Copt an input array and return a pointer to it
char* copy_array(const char* input_array, size_t length) {
    char* ret = new char[length];
    for(int i = 0; i < length; i++) {
        ret[i] = input_array[i];
    }
    delete[] input_array;
    return ret;
}

int main() {
    int* x = new int(5);
    cout << *x << endl;
    delete x;

    char* name = new char[4];
    name[0] = 'B';
    name[1] = 'e';
    name[2] = 'n';
    name[3] = '\0';

    char* new_array = copy_array(name, 4);
    cout << new_array << endl;
    delete[] new_array;
}