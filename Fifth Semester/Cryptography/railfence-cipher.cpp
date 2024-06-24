#include <iostream>
#include <string>
using namespace std;

string encryptRailFence(string text, int key)
{
    if (key == 1)
        return text;

    int len = text.length();
    string *rail = new string[key];

    bool dir_down = false;
    int row = 0;

    for (int i = 0; i < len; ++i)
    {
        rail[row] += text[i];
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }

    string result;
    for (int i = 0; i < key; ++i)
        result += rail[i];

    delete[] rail;
    return result;
}

string decryptRailFence(string cipher, int key)
{
    if (key == 1)
        return cipher;

    int len = cipher.length();
    char **rail = new char *[key];
    for (int i = 0; i < key; ++i)
        rail[i] = new char[len];

    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            rail[i][j] = '\n';

    bool dir_down = false;
    int row = 0;

    for (int i = 0; i < len; ++i)
    {
        rail[row][i] = '*';
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < key; ++i)
        for (int j = 0; j < len; ++j)
            if (rail[i][j] == '*')
                rail[i][j] = cipher[index++];

    string result;
    row = 0;
    dir_down = false;

    for (int i = 0; i < len; ++i)
    {
        result += rail[row][i];
        if (row == 0 || row == key - 1)
            dir_down = !dir_down;
        row += dir_down ? 1 : -1;
    }

    for (int i = 0; i < key; ++i)
        delete[] rail[i];
    delete[] rail;

    return result;
}

int main()
{
    string text = "HELLO WORLD";
    int key = 3;

    string encrypted = encryptRailFence(text, key);
    string decrypted = decryptRailFence(encrypted, key);

    cout << "Original text: " << text << endl;
    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}