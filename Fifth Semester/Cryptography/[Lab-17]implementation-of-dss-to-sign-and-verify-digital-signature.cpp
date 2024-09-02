#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

long long power(long long base, long long exp, long long mod) {
  long long result = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;
    exp = exp >> 1;
    base = (base * base) % mod;
  }
  return result;
}

long long modInverse(long long a, long long q) {
  long long q0 = q, t, quotient;
  long long x0 = 0, x1 = 1;
  if (q == 1)
    return 0;
  while (a > 1) {
    quotient = a / q;
    t = q;
    q = a % q, a = t;
    t = x0;
    x0 = x1 - quotient * x0;
    x1 = t;
  }
  if (x1 < 0)
    x1 += q0;
  return x1;
}

void generateKeys(long long &p, long long &q, long long &g, long long &x,
                  long long &y) {
  p = 23;
  q = 11;
  g = 2;
  x = rand() % (q - 1) + 1;
  y = power(g, x, p);
}

void sign(long long p, long long q, long long g, long long x, long long m,
          long long &r, long long &s) {
  long long k = rand() % (q - 1) + 1;
  r = power(g, k, p) % q;
  s = (modInverse(k, q) * (m + x * r)) % q;
}

bool verify(long long p, long long q, long long g, long long y, long long m,
            long long r, long long s) {
  long long w = modInverse(s, q);
  long long u1 = (m * w) % q;
  long long u2 = (r * w) % q;
  long long v = ((power(g, u1, p) * power(y, u2, p)) % p) % q;
  return v == r;
}

int main() {
  srand(time(0));
  long long p, q, g, x, y;
  generateKeys(p, q, g, x, y);
  std::cout << "Public Key: (p=" << p << ", q=" << q << ", g=" << g
            << ", y=" << y << ")\n";
  std::cout << "Private Key: x=" << x << "\n";

  long long message = 91; // Example message
  std::cout << "Original Message: " << message << "\n";

  long long r, s;
  sign(p, q, g, x, message, r, s);
  std::cout << "Signature: (r=" << r << ", s=" << s << ")\n";

  bool isVerified = verify(p, q, g, y, message, r, s);
  std::cout << "Verification: " << (isVerified ? "Success" : "Failure") << "\n";
  return 0;
}
