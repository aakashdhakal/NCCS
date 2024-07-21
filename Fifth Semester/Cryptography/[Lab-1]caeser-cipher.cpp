#include <iostream>
using namespace std;
 
// This function receives text and shift and
// returns the encrypted text
string encrypt(string text, int s)
{
    string result = "";
 
    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
 
        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }
 
    // Return the resulting string
    return result;
}

string decrypt(string cipher, int s){
 string result = "";
 
    // traverse text
    for (int i = 0; i < cipher.length(); i++) {
        // apply transformation to each character
        // Decrypt Uppercase letters

        if (isupper(cipher[i]))
            result += char(int(cipher[i] - s - 65) % 26 + 65);
 
        // Decrypt Lowercase letters
        else
            result += char(int(cipher[i] - s - 97) % 26 + 97);
    }
 
    // Return the resulting string
    return result;
}
 
// Driver program to test the above function
int main()
{
    string text;
    cout << "Enter the plain text: ";
    cin >> text;
    int s;
    cout << "Enter the no. of shift: ";
    cin >> s;
    string cipher = encrypt(text, s);
    cout << "Text : " << text;
    cout << "\nShift: " << s;
    cout << "\nCipher: " << cipher;
    cout << "\nDecryption: " << decrypt(cipher, s)<<endl;

    return 0;
}
