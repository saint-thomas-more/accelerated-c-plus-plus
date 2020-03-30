// Work with command line arguments

#include <iostream>

using namespace std;

int main(int argc, char** argv){
    cout << "This program is called: " << argv[0] << endl;

    for(int i = 1; i < argc; i++) {
        cout << "Argument " << i << " is " << argv[i] << endl;
    }
    return 0;
}