#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Check if first character is a letter or underscore
    if (!isalpha(str[0]) && str[0] != '_')
    {
        cout << "Invalid identifier" << endl;
        return 0;
    }

    // Check if remaining characters are letters, digits or underscore
    for (int i = 1; i < str.size(); i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            cout << "Invalid identifier" << endl;
            return 0;
        }
    }

    // Check if string is a keyword
    set<string> keywords = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    if (keywords.find(str) != keywords.end())
    {
        cout << "Keyword" << endl;
    }
    else
    {
        cout << "Valid identifier" << endl;
    }

    return 0;
}
