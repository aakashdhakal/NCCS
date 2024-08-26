#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() { return 1 + rand() % 5; }

int main() {
  srand(time(0));
  int sa = rollDice() + rollDice();
  int sb = rollDice() + rollDice();
  printf("Player A: %d\nPlayer B: %d\n", sa, sb);
  printf("%c wins the game by %d points\n", (sa > sb) ? 'A' : 'B',
         (sa > sb) ? sa : sb);
  return 0;
}