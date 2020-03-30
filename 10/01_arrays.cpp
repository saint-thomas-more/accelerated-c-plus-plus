// PoC of usage of arrays and char* as strings

#include <iostream>

using namespace std;

size_t length(const char *p) {
    size_t ret = 0;
    while(*p != '\0') {
        ret++;
        *p++;
    }
    return ret;
}

int main() {
    char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    cout << length(hello) << endl;
    return 0;
}