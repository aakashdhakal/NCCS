
#include <stdio.h>
#include <math.h>
int convert(long long);

int main() {
  long long binaryNumber;
  printf("Enter a binary number: ");
  scanf("%lld", &binaryNumber);
  printf("%lld in binary = %d in decimal", binaryNumber, convert(binaryNumber));
  return 0;
}

int convert(long long binaryNumber) {
  int dec = 0, i = 0, rem;

  while (binaryNumber!=0) {
    rem = binaryNumber % 10;
    binaryNumber /= 10;
    dec += rem * pow(2, i);
    ++i;
  }

  return dec;
}
