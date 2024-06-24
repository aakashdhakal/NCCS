#include <iostream>
using namespace std;
int extendedEuclidean(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}
int modInverse(int a, int n)
{
    int x, y;
    int gcd = extendedEuclidean(a, n, x, y);

    if (gcd != 1)
    {
        return -1;
    }
    return (x % n + n) % n;
}
int main()
{
    int a, n;
    cout << "Enter the number whose multiplicative inverse you want to find: ";
    cin >> a;
    cout << "Enter the value of n: ";
    cin >> n;
    int inverse = modInverse(a, n);
    if (inverse == -1)
    {
        cout << "Multiplicative inverse of " << a << " modulo " << n << " doesn't exist." << endl;
    }
    else
    {
        cout << "Multiplicative inverse of " << a << " modulo " << n << " is " << inverse << endl;
    }
    return 0;
}