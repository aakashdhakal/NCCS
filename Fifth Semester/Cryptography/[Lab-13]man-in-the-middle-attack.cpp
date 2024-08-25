#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
// Function to calculate (base^exp) % mod
int modExp(int base, int exp, int mod) {
  int result = 1;
  base = base % mod;
  while (exp > 0) {
    if (exp % 2 == 1) // If exp is odd, multiply base with result
      result = (result * base) % mod;
    exp = exp >> 1;             // exp = exp / 2
    base = (base * base) % mod; // base = base^2 % mod
  }
  return result;
}
// Function to perform Diffie-Hellman key exchange
void diffieHellman(int p, int g, int private_key, int &public_key) {
  // Calculate public key
  public_key = modExp(g, private_key, p);
}
int main() {
  // Constants (shared by Alice and Bob)
  int p, g;
  // Input prime number (p)
  cout << "Enter prime number (p): ";
  cin >> p;
  // Input base value (g)
  cout << "Enter base value (g): ";
  cin >> g;
  // Alice's private key and public key
  int alice_private_key;
  int alice_public_key;
  // Bob's private key and public key
  int bob_private_key;
  int bob_public_key;
  // Eve's private key and public key
  int eve_private_key;
  int eve_public_key;
  // Randomly generate private keys for Alice, Bob, and Eve
  srand(time(NULL)); // Use NULL instead of nullptr for older compilers
  alice_private_key = rand() % (p - 1) + 1;
  bob_private_key = rand() % (p - 1) + 1;
  eve_private_key = rand() % (p - 1) + 1;
  // Eve intercepts and modifies the public keys exchanged between Alice and Bob
  diffieHellman(p, g, eve_private_key, eve_public_key);
  // Alice and Bob exchange their public keys (but Eve intercepts and replaces
  // them)
  diffieHellman(p, g, alice_private_key, alice_public_key);
  bob_public_key = alice_public_key; // Eve intercepts Alice's public key
  diffieHellman(p, g, bob_private_key, bob_public_key);
  alice_public_key = bob_public_key; // Eve intercepts Bob's public key
  // Eve establishes separate keys with Alice and Bob
  int eve_shared_secret_with_alice =
      modExp(alice_public_key, eve_private_key, p);
  int eve_shared_secret_with_bob = modExp(bob_public_key, eve_private_key, p);
  cout << "Eve's Shared Secret with Alice: " << eve_shared_secret_with_alice
       << endl;
  cout << "Eve's Shared Secret with Bob: " << eve_shared_secret_with_bob
       << endl;
  // Alice and Bob establish their own shared secret
  int alice_shared_secret = modExp(bob_public_key, alice_private_key, p);
  int bob_shared_secret = modExp(alice_public_key, bob_private_key, p);
  cout << "Alice's Shared Secret with Bob: " << alice_shared_secret << endl;
  cout << "Bob's Shared Secret with Alice: " << bob_shared_secret << endl;
  return 0;
}