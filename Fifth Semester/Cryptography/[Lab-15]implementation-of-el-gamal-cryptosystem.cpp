#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

long long power(long long a, long long b, long long p) {
  long long result = 1;
  a = a % p;
  while (b > 0) {
    if (b % 2 == 1)
      result = (result * a) % p;
    b = b >> 1;
    a = (a * a) % p;
  }
  return result;
}

long long modInverse(long long a, long long p) { return power(a, p - 2, p); }

void generateKeys(long long &p, long long &g, long long &x, long long &y) {
  p = 23;
  g = 5;
  x = rand() % (p - 1) + 1;
  y = power(g, x, p);
}

void encrypt(long long p, long long g, long long y, long long m, long long &c1,
             long long &c2) {
  long long k = rand() % (p - 1) + 1;
  c1 = power(g, k, p);
  c2 = (m * power(y, k, p)) % p;
}

long long decrypt(long long p, long long x, long long c1, long long c2) {
  long long s = power(c1, x, p);
  return (c2 * modInverse(s, p)) % p;
}

int main() {
  srand(time(0));
  long long p, g, x, y;
  generateKeys(p, g, x, y);
  std::cout << "Public Key: (p=" << p << ", g=" << g << ", y=" << y << ")\n";
  std::cout << "Private Key: x=" << x << "\n";

  long long message = 15;
  std::cout << "Original Message: " << message << "\n";

  long long c1, c2;
  encrypt(p, g, y, message, c1, c2);
  std::cout << "Encrypted Message: (" << c1 << ", " << c2 << ")\n";

  long long decryptedMessage = decrypt(p, x, c1, c2);
  std::cout << "Decrypted Message: " << decryptedMessage << "\n";
  return 0;
}
