#include <iostream>
#include <string>
using namespace std;

string xor_encrypt_decrypt(const string &input, const string &key)
{
    string output = input;

    for (size_t i = 0; i < input.size(); i++)
    {
        output[i] = input[i] ^ key[i % key.size()];
    }

    return output;
}

int main()
{
    string message = "Hello, World!";
    string key = "SECRETKEY";

    string encrypted = xor_encrypt_decrypt(message, key);
    string decrypted = xor_encrypt_decrypt(encrypted, key);

    cout << "Original message: " << message << endl;
    cout << "Encrypted message: " << encrypted << endl;
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}