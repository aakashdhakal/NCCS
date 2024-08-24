#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int phi(int n) {
  int result = n;
  for (int p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0)
        n /= p;
      result -= result / p;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}

int power(int x, int y, int p) {
  int res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1)
      res = (res * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return res;
}

int findPrimitive(int n) {
  int phi_n = phi(n);
  std::vector<int> factors;
  for (int i = 2; i * i <= phi_n; i++) {
    if (phi_n % i == 0) {
      factors.push_back(i);
      while (phi_n % i == 0)
        phi_n /= i;
    }
  }
  if (phi_n > 1)
    factors.push_back(phi_n);

  for (int r = 2; r <= n; r++) {
    bool flag = false;
    for (int factor : factors) {
      if (power(r, phi(n) / factor, n) == 1) {
        flag = true;
        break;
      }
    }
    if (!flag)
      return r;
  }
  return -1;
}

int main() {
  int n;
  cout << "Enter the number: ";
  cin >> n;
  cout << "Smallest primitive root of " << n << " is  " << findPrimitive(n)
       << endl;
  return 0;
}