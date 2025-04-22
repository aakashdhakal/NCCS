#include <bits/stdc++.h>
#define MAX_STACK 100
using namespace std;

// Class representing a single stack element
class StackElement {
public:
  int state;
  char symbol;

  StackElement(int state = 0, char symbol = '$')
      : state(state), symbol(symbol) {}
};

// Class representing a production rule
class Production {
public:
  char nonTerminal;
  string production;
  int length;

  Production(char nonTerminal, const string &production)
      : nonTerminal(nonTerminal), production(production),
        length(production.length()) {}
};

// Class representing the LR Parser
class LRParser {
private:
  StackElement parseStack[MAX_STACK];
  int top;

  vector<Production> productions;

  const int ACTION[7][3] = {
      {2, 3, 0},  // State 0
      {0, 0, 1},  // State 1 (Accept)
      {2, 3, 0},  // State 2
      {0, 0, -3}, // State 3 (Reduce A->b)
      {0, 0, -1}, // State 4 (Reduce S->AA)
      {2, 3, 0},  // State 5
      {0, 0, -2}  // State 6 (Reduce A->aA)
  };

  const int GOTO[7][2] = {
      {4, 1}, // State 0
      {0, 0}, // State 1
      {6, 0}, // State 2
      {0, 0}, // State 3
      {0, 0}, // State 4
      {0, 0}, // State 5
      {0, 0}  // State 6
  };

  int getColumnIndex(char input) {
    switch (input) {
    case 'a':
      return 0;
    case 'b':
      return 1;
    case '$':
      return 2;
    case 'A':
      return 0;
    case 'S':
      return 1;
    default:
      return -1;
    }
  }

  void push(int state, char symbol) {
    if (top >= MAX_STACK - 1) {
      cout << "Stack overflow\n";
      exit(1);
    }
    parseStack[++top] = StackElement(state, symbol);
  }

  void pop(int count) {
    top -= count;
    if (top < -1) {
      cout << "Stack underflow\n";
      exit(1);
    }
  }

  string getStackString() {
    stringstream ss;
    for (int i = 0; i <= top; i++) {
      ss << "(" << parseStack[i].state << ", " << parseStack[i].symbol << ") ";
    }
    return ss.str();
  }

  void printTableHeader() {
    cout << "\nAction\tState\tSymbol\tNext State/Production\t\t\tStack\n";
    cout << "---------------------------------------------------------------\n";
  }

public:
  LRParser() : top(-1) {
    productions.emplace_back('S', "AA"); // 0
    productions.emplace_back('A', "aA"); // 1
    productions.emplace_back('A', "b");  // 2
  }

  bool parse(const string &input) {
    int currentPos = 0;
    push(0, '$');
    printTableHeader();

    while (true) {
      char currentInput = input[currentPos];
      int currentState = parseStack[top].state;
      int col = getColumnIndex(currentInput);

      if (col == -1) {
        cout << "Invalid input symbol: " << currentInput << endl;
        return false;
      }

      int action = ACTION[currentState][col];

      if (action == 1 && currentInput == '$') {
        printf("Accept\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
        return true;
      } else if (action > 0) {
        printf("Shift\t\t%d\t%c\t\t%d\t\t\t\t%s\n", currentState, currentInput,
               action, getStackString().c_str());
        push(action, currentInput);
        currentPos++;
      } else if (action < 0) {
        int productionIndex = -action - 1;
        Production &prod = productions[productionIndex];

        printf("Reduce\t\t%d\t%c\tby production %d\t\t\t%s\n", currentState,
               currentInput, productionIndex, getStackString().c_str());
        pop(prod.length);
        int newState =
            GOTO[parseStack[top].state][getColumnIndex(prod.nonTerminal)];
        printf("Goto\t\t\t\t\t\t\t%d\t\t\t\t%s\n", newState,
               getStackString().c_str());
        push(newState, prod.nonTerminal);
      } else {
        cout << "Syntax error at position " << currentPos << endl;
        return false;
      }
    }
  }
};

int main() {
  LRParser parser;
  string input;

  cout << "Enter input string (end with $): ";
  cin >> input;

  if (parser.parse(input)) {
    cout << "Parsing completed successfully\n";
  } else {
    cout << "Parsing failed\n";
  }

  return 0;
}
