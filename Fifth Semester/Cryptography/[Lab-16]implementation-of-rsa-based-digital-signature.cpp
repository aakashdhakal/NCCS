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

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void generateKeys(long long &n, long long &e, long long &d) {
  long long p = 61, q = 53; // Example primes
  n = p * q;
  long long phi = (p - 1) * (q - 1);
  e = 17;
  while (gcd(e, phi) != 1)
    e++;
  d = power(e, phi - 1, phi);
}

long long sign(long long msg, long long d, long long n) {
  return power(msg, d, n);
}

bool verify(long long msg, long long sig, long long e, long long n) {
  return msg == power(sig, e, n);
}

int main() {
  srand(time(0));
  long long n, e, d;
  generateKeys(n, e, d);
  std::cout << "Public Key: (n=" << n << ", e=" << e << ")\n";
  std::cout << "Private Key: d=" << d << "\n";

  long long message = 91; // Example message
  std::cout << "Original Message: " << message << "\n";

  long long signature = sign(message, d, n);
  std::cout << "Signature: " << signature << "\n";

  bool isVerified = verify(message, signature, e, n);
  std::cout << "Verification: " << (isVerified ? "Success" : "Failure") << "\n";
  return 0;
}
