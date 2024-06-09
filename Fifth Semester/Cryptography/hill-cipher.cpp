#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

float encrypt[2][1] = {{0}, {0}}, decrypt[2][1] = {{0}, {0}}, a[2][2], b[2][2] = {{0}}, mes[2][1] = {{0}}, c[2][2] = {{0}};
void inverse()
{
    int i, j;
    float det = 0;

    // Calculate the determinant
    det = a[0][0] * a[1][1] - a[0][1] * a[1][0];

    if (det == 0)
    {
        cout << "The key matrix is not invertible.\n";
        exit(1);
    }

    // Calculate the inverse matrix
    float invdet = 1.0 / det;
    b[0][0] = a[1][1] * invdet;
    b[0][1] = -a[0][1] * invdet;
    b[1][0] = -a[1][0] * invdet;
    b[1][1] = a[0][0] * invdet;
}

void encryption()
{
    int i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 2; k++)
                encrypt[i][j] += a[i][k] * mes[k][j];

    cout << "\nEncrypted string is: ";
    for (i = 0; i < 2; i++)
        cout << (char)(fmod(encrypt[i][0], 26) + 97);
}

void decryption()
{
    int i, j, k;
    inverse();
    for (i = 0; i < 2; i++)
        for (j = 0; j < 1; j++)
            for (k = 0; k < 2; k++)
                decrypt[i][j] += b[i][k] * encrypt[k][j];

    cout << "\nDecrypted string is: ";
    for (i = 0; i < 2; i++)
        cout << (char)(fmod(decrypt[i][0], 26) + 97);
    cout << endl;
}

void getKeyMessage()
{
    int i, j;
    char msg[2];

    cout << "Enter 2x2 matrix for key (It should be invertible):\n";
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            cin >> a[i][j];
            c[i][j] = a[i][j];
        }

    cout << "\nEnter a 2 letter string: ";
    cin >> msg;
    for (i = 0; i < 2; i++)
        mes[i][0] = msg[i] - 97;
}

int main()
{
    getKeyMessage();
    encryption();
    decryption();
    return 0;
}
