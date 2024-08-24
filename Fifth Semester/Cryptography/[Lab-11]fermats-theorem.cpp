#include <cstdlib>
#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int power(int x, unsigned int y, unsigned int m);
void modInverse(int a, int m) {
  if (gcd(a, m) != 1)
    cout << "Inverse doesn't exist" << endl;
  else {
    cout << "Modular multiplicative inverse is " << power(a, m - 2, m) << endl;
  }
}
int power(int x, unsigned int y, unsigned int m) {
  if (y == 0)
    return 1;
  int p = power(x, y / 2, m) % m;
  p = (p * p) % m;

  return (y % 2 == 0) ? p : (x * p) % m;
}
int main() {
  int a, p;
  cout << "Enter a integer: ";
  cin >> a;
  cout << "Enter a prime modular divisor: ";
  cin >> p;
  modInverse(a, p);
  return 0;
}