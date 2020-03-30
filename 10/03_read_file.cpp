// Read a file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    string line;
    ifstream input_file("genesis.txt");
    if(input_file.is_open()) {
        while(getline(input_file, line)) {
            cout << line << endl;
        }
    }
    return 0;
}