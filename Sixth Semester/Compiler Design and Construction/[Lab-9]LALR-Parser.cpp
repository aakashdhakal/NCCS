#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;
char input[MAX];

void push(char c) { stack[++top] = c; }

void pop(int count) { top -= count; }

void printStackAndInput(int index) {
  printf("\nStack: ");
  for (int i = 0; i <= top; i++) {
    printf("%c", stack[i]);
  }
  printf("\tInput: ");
  for (int i = index; i < strlen(input); i++) {
    printf("%c", input[i]);
  }
  printf("\tAction: ");
}

char peek(int pos) {
  if (top - pos >= 0) {
    return stack[top - pos];
  }
  return '\0';
}

int reduce() {
  int reduced = 0;

  do {
    reduced = 0;

    printf("\nChecking reductions for stack: ");
    for (int i = 0; i <= top; i++) {
      printf("%c", stack[i]);
    }

    // Rule 1: digit → F
    if (isdigit(peek(0))) {
      printf("\nReducing digit %c to F", stack[top]);
      stack[top] = 'F';
      reduced = 1;
      continue;
    }

    // Rule 2: F → T (when not part of multiplication)
    if (peek(0) == 'F' && peek(1) != '*') {
      printf("\nReducing F to T");
      stack[top] = 'T';
      reduced = 1;
      continue;
    }

    // Rule 3: T * F → T (handle multiplication)
    if (peek(0) == 'F' && peek(1) == '*' && peek(2) == 'T') {
      printf("\nReducing T * F to T");
      pop(2);
      stack[top] = 'T';
      reduced = 1;
      continue;
    }

    // Rule 4: E * F → T (new rule to handle E*F case)
    if (peek(0) == 'F' && peek(1) == '*' && peek(2) == 'E') {
      printf("\nReducing E * F to T");
      pop(2);
      stack[top] = 'T';
      reduced = 1;
      continue;
    }

    // Rule 5: T → E (when not part of addition)
    if (peek(0) == 'T' && peek(1) != '+') {
      printf("\nReducing T to E");
      stack[top] = 'E';
      reduced = 1;
      continue;
    }

    // Rule 6: E + T → E (handle addition)
    if (peek(0) == 'T' && peek(1) == '+' && peek(2) == 'E') {
      printf("\nReducing E + T to E");
      pop(2);
      stack[top] = 'E';
      reduced = 1;
      continue;
    }

  } while (reduced);

  return reduced;
}

void parseExpression() {
  printf("\nParsing Expression: %s\n", input);
  printf("\nTrace of parsing steps:");

  int i = 0;
  while (i < strlen(input)) {
    printStackAndInput(i);
    printf("Shift %c", input[i]);
    push(input[i]);
    i++;
    reduce();
  }

  // Keep reducing until no more reductions are possible
  printf("\n\nPerforming final reductions:");
  while (1) {
    int did_reduce = reduce();
    if (!did_reduce)
      break;
  }

  printf("\n\nFinal stack: ");
  for (int i = 0; i <= top; i++) {
    printf("%c", stack[i]);
  }

  if (top == 0 && stack[top] == 'E') {
    printf("\n✅ Accepted: Valid Expression!\n");
  } else {
    printf("\n❌ Rejected: Invalid Expression!\n");
    printf("Expected single 'E' on stack, found: ");
    for (int i = 0; i <= top; i++) {
      printf("%c", stack[i]);
    }
    printf("\n");
  }
}

int main() {
  printf("Enter an arithmetic expression (use digits, +, *): ");
  scanf("%s", input);

  // Input validation
  for (int i = 0; i < strlen(input); i++) {
    if (!isdigit(input[i]) && input[i] != '+' && input[i] != '*') {
      printf("\n❌ Invalid character in expression: %c\n", input[i]);
      return 1;
    }
  }

  parseExpression();
  return 0;
}