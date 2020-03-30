#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

void write_file(string filename, ofstream& os) {
    ifstream input_fs(filename);
    string line;
    if(input_fs.is_open()) {
        while(getline(input_fs, line)) {
            os << line << endl;
        }
    }
    input_fs.close();  
}

int main() {
    ofstream output_fs;
    output_fs.open("genesis2.txt");

    write_file("genesis.txt", output_fs);
    output_fs.close();
    remove("genesis2.txt");
}