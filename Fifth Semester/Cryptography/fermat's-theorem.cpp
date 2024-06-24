#include <iostream>
using namespace std;

// Function to compute a^b under modulo m using binary exponentiation
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Function to check Fermat's Little Theorem
bool checkFermat(int a, int p)
{
    // Fermat's theorem is only applicable if p is a prime number
    if (p == 1)
        return false; // 1 is not a prime number
    // According to Fermat's Little Theorem, a^(p-1) % p = 1 for a prime p
    return binpow(a, p - 1, p) == 1;
}

int main()
{
    int a, p;
    cout << "Enter a and p to check Fermat's Little Theorem (a^(p-1) = 1 (mod p)): ";
    cin >> a >> p;

    if (checkFermat(a, p))
        cout << "Fermat's theorem holds for a = " << a << " and p = " << p << endl;
    else
        cout << "Fermat's theorem does not hold for a = " << a << " and p = " << p << endl;

    return 0;
}