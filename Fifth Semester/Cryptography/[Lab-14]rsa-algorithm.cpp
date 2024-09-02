#include <cmath>
#include <iostream>
using namespace std;

// find gcd
int gcd(int a, int b) {
  int t;
  while (1) {
    t = a % b;
    if (t == 0)
      return b;
    a = b;
    b = t;
  }
}

int main() {
  // 2 random prime numbers
  double p = 13;
  double q = 11;
  double n = p * q;               // calculate n
  double phi = (p - 1) * (q - 1); // calculate phi

  // public key
  // e stands for encrypt
  double e = 7;
  // for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n)
  // are coprime.
  while (e < phi) {
    if (gcd(e, phi) == 1)
      break;
    else
      e++;
  }

  // private key
  // d stands for decrypt
  double d;
  // k can be any arbitrary value
  double k = 2;
  // choose d such that it satisfies d*e = 1 + k*phi
  d = (1 + (k * phi)) / e;

  // message to be encrypted
  double msg = 13;
  cout << "Message data = " << msg << endl;

  // encryption c = (msg ^ e) % n
  double c = fmod(pow(msg, e), n);
  cout << "Encrypted data = " << c << endl;

  // decryption m = (c ^ d) % n
  double m = fmod(pow(c, d), n);
  cout << "Original Message Sent = " << m << endl;

  return 0;
}