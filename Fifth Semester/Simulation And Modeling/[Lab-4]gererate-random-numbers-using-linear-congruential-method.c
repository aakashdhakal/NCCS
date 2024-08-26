#include <stdio.h>
#include <stdlib.h>

int main() {
  int x0, x, a, c, M = 101, iterations;
  double r;

  // Get user input
  printf("Enter the initial seed (x0): ");
  scanf("%d", &x0);
  printf("Enter the multiplier (a): ");
  scanf("%d", &a);
  printf("Enter the increment (c): ");
  scanf("%d", &c);
  printf("Enter the number of iterations: ");
  scanf("%d", &iterations);

  for (int i = 1; i <= iterations; i++) {
    x = (a * x0 + c) % M;
    r = ((double)x / M);
    printf("%f\n", r);
    x0 = x;
  }

  return 0;
}