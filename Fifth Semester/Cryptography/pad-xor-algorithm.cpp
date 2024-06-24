#include <iostream>
#include <string>

using namespace std;

string stringEncryption(string text, string key)
{
    string cipherText = "";
    int cipher[key.length()];

    for (int i = 0; i < key.length(); i++)
    {
        cipher[i] = text.at(i) - 'A' + key.at(i) - 'A';
    }

    for (int i = 0; i < key.length(); i++)
    {
        if (cipher[i] > 25)
        {
            cipher[i] = cipher[i] - 26;
        }
    }

    for (int i = 0; i < key.length(); i++)
    {
        int x = cipher[i] + 'A';
        cipherText += (char)x;
    }

    return cipherText;
}

static string stringDecryption(string s, string key)
{
    string plainText = "";
    int plain[key.length()];

    for (int i = 0; i < key.length(); i++)
    {
        plain[i] = s.at(i) - 'A' - (key.at(i) - 'A');
    }

    for (int i = 0; i < key.length(); i++)
    {
        if (plain[i] < 0)
        {
            plain[i] = plain[i] + 26;
        }
    }

    for (int i = 0; i < key.length(); i++)
    {
        int x = plain[i] + 'A';
        plainText += (char)x;
    }

    return plainText;
}

int main()
{
    string plainText = "Hello";
    string key = "MONEY";

    for (int i = 0; i < plainText.length(); i++)
    {
        plainText[i] = toupper(plainText[i]);
    }
    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }
    string encryptedText = stringEncryption(plainText, key);

    cout << "Cipher Text - " << encryptedText << endl;
    cout << "Message - " << stringDecryption(encryptedText, key);

    return 0;
}