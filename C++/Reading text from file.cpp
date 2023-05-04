#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string text;
    fstream file;
    file.open("abc.txt", ios::in|ios::out);

    cout << "Enter text to save in file: ";
    getline(cin, text);
    file << text;

    file.seekg(0, ios::beg);
    
    while (getline(file, text)) {
        cout << text << endl;
    }
    file.close();
    return 0;
}
