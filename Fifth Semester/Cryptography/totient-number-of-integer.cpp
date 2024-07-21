#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int phi(int n)
{
    int result = 1;
    for (int i = 2; i < n; ++i)
    {
        if (gcd(i, n) == 1)
        {
            ++result;
        }
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    cout << "Euler's Totient function f(" << n << ") = " << phi(n) << endl;

    return 0;
}
