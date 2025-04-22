#include <cstring>
#include <iostream>
using namespace std;

#define MAX_RULES 10
#define MAX_SYMBOLS 10
#define MAX_TERMINALS 10
#define MAX_NON_TERMINALS 10

char grammar[MAX_RULES][MAX_SYMBOLS];
char first[MAX_NON_TERMINALS][MAX_TERMINALS] = {};
char follow[MAX_NON_TERMINALS][MAX_TERMINALS] = {};
char nonTerminals[MAX_NON_TERMINALS];
char terminals[MAX_TERMINALS];
int ruleCount = 0, ntCount = 0, tCount = 0;

bool isTerminal(char ch) { return !(ch >= 'A' && ch <= 'Z'); }

void addToSet(char set[][MAX_TERMINALS], int index, char ch) {
  for (int i = 0; set[index][i] != '\0'; i++) {
    if (set[index][i] == ch)
      return;
  }
  int len = strlen(set[index]);
  set[index][len] = ch;
  set[index][len + 1] = '\0';
}

int findIndex(char ch, char symbols[], int count) {
  for (int i = 0; i < count; i++) {
    if (symbols[i] == ch)
      return i;
  }
  return -1;
}

void computeFirst() {
  bool changed;
  do {
    changed = false;
    for (int i = 0; i < ruleCount; i++) {
      int lhsIdx = findIndex(grammar[i][0], nonTerminals, ntCount);
      int k = 3;
      bool epsilonInPrev = true;

      while (grammar[i][k] != '\0' && epsilonInPrev) {
        char symbol = grammar[i][k];
        epsilonInPrev = false;

        if (isTerminal(symbol)) {
          if (strchr(first[lhsIdx], symbol) == NULL) {
            addToSet(first, lhsIdx, symbol);
            changed = true;
          }
          break;
        } else {
          int idx = findIndex(symbol, nonTerminals, ntCount);
          for (int m = 0; first[idx][m] != '\0'; m++) {
            if (first[idx][m] == '#') {
              epsilonInPrev = true;
            } else if (strchr(first[lhsIdx], first[idx][m]) == NULL) {
              addToSet(first, lhsIdx, first[idx][m]);
              changed = true;
            }
          }
        }
        k++;
      }

      if (epsilonInPrev) {
        if (strchr(first[lhsIdx], '#') == NULL) {
          addToSet(first, lhsIdx, '#');
          changed = true;
        }
      }
    }
  } while (changed);
}

void computeFollow() {
  follow[0][0] = '$';
  follow[0][1] = '\0';
  bool changed;
  do {
    changed = false;
    for (int i = 0; i < ruleCount; i++) {
      char lhs = grammar[i][0];
      int lhsIdx = findIndex(lhs, nonTerminals, ntCount);
      for (int j = 3; grammar[i][j] != '\0'; j++) {
        char curr = grammar[i][j];
        if (!isTerminal(curr)) {
          int currIdx = findIndex(curr, nonTerminals, ntCount);
          bool epsilon = true;
          int k = j + 1;

          while (grammar[i][k] != '\0' && epsilon) {
            epsilon = false;
            char next = grammar[i][k];
            if (isTerminal(next)) {
              if (strchr(follow[currIdx], next) == NULL) {
                addToSet(follow, currIdx, next);
                changed = true;
              }
              break;
            } else {
              int nextIdx = findIndex(next, nonTerminals, ntCount);
              for (int m = 0; first[nextIdx][m] != '\0'; m++) {
                if (first[nextIdx][m] != '#' &&
                    strchr(follow[currIdx], first[nextIdx][m]) == NULL) {
                  addToSet(follow, currIdx, first[nextIdx][m]);
                  changed = true;
                }
                if (first[nextIdx][m] == '#') {
                  epsilon = true;
                }
              }
            }
            k++;
          }

          if (epsilon || grammar[i][j + 1] == '\0') {
            for (int m = 0; follow[lhsIdx][m] != '\0'; m++) {
              if (strchr(follow[currIdx], follow[lhsIdx][m]) == NULL) {
                addToSet(follow, currIdx, follow[lhsIdx][m]);
                changed = true;
              }
            }
          }
        }
      }
    }
  } while (changed);
}

void fillParsingTable(char parsingTable[][MAX_TERMINALS][MAX_RULES]) {
  for (int i = 0; i < ruleCount; i++) {
    char lhs = grammar[i][0];
    int lhsIdx = findIndex(lhs, nonTerminals, ntCount);
    int k = 3;
    bool epsilon = true;

    while (grammar[i][k] != '\0' && epsilon) {
      char symbol = grammar[i][k];
      epsilon = false;

      if (isTerminal(symbol)) {
        int termIdx = findIndex(symbol, terminals, tCount);
        strcpy(parsingTable[lhsIdx][termIdx], grammar[i]);
        break;
      } else {
        int symIdx = findIndex(symbol, nonTerminals, ntCount);
        for (int m = 0; first[symIdx][m] != '\0'; m++) {
          if (first[symIdx][m] == '#') {
            epsilon = true;
          } else {
            int termIdx = findIndex(first[symIdx][m], terminals, tCount);
            strcpy(parsingTable[lhsIdx][termIdx], grammar[i]);
          }
        }
      }
      k++;
    }

    if (epsilon) {
      for (int m = 0; follow[lhsIdx][m] != '\0'; m++) {
        int termIdx = findIndex(follow[lhsIdx][m], terminals, tCount);
        strcpy(parsingTable[lhsIdx][termIdx], grammar[i]);
      }
    }
  }
}

void displayParsingTable(char parsingTable[][MAX_TERMINALS][MAX_RULES]) {
  cout << "\nParsing Table:\n\t";
  for (int j = 0; j < tCount; j++) {
    cout << terminals[j] << "\t";
  }
  cout << endl;

  for (int i = 0; i < ntCount; i++) {
    cout << nonTerminals[i] << "\t";
    for (int j = 0; j < tCount; j++) {
      if (parsingTable[i][j][0] != '\0') {
        cout << parsingTable[i][j] << "\t";
      } else {
        cout << "-\t";
      }
    }
    cout << endl;
  }
}

int main() {
  cout << "Enter number of rules: ";
  cin >> ruleCount;

  cout << "Enter grammar rules (e.g., S->AB or A->a):" << endl;
  for (int i = 0; i < ruleCount; i++) {
    cin >> grammar[i];
  }

  for (int i = 0; i < ruleCount; i++) {
    char lhs = grammar[i][0];
    if (findIndex(lhs, nonTerminals, ntCount) == -1) {
      nonTerminals[ntCount++] = lhs;
    }
    for (int j = 3; grammar[i][j] != '\0'; j++) {
      if (isTerminal(grammar[i][j]) &&
          findIndex(grammar[i][j], terminals, tCount) == -1 &&
          grammar[i][j] != '#') {
        terminals[tCount++] = grammar[i][j];
      }
    }
  }

  terminals[tCount++] = '$';

  computeFirst();
  computeFollow();

  cout << "\nFIRST sets:\n";
  for (int i = 0; i < ntCount; i++) {
    cout << nonTerminals[i] << " : { ";
    for (int j = 0; first[i][j] != '\0'; j++) {
      cout << first[i][j] << " ";
    }
    cout << "}\n";
  }

  cout << "\nFOLLOW sets:\n";
  for (int i = 0; i < ntCount; i++) {
    cout << nonTerminals[i] << " : { ";
    for (int j = 0; follow[i][j] != '\0'; j++) {
      cout << follow[i][j] << " ";
    }
    cout << "}\n";
  }

  char parsingTable[MAX_NON_TERMINALS][MAX_TERMINALS][MAX_RULES] = {};
  fillParsingTable(parsingTable);
  displayParsingTable(parsingTable);

  return 0;
}
