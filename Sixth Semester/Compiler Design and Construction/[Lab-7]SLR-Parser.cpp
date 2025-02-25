#include <cstdlib>  // Include cstdlib for exit function
#include <iostream> // Include iostream for input/output operations
#include <sstream>  // Include sstream for string stream operations
#include <string>   // Include string for string operations

#define MAX_STACK 100 // Define maximum stack size

using namespace std; // Use standard namespace

// Define a class for stack elements
class StackElement {
public:
  int state;   // State number
  char symbol; // Grammar symbol
};

// Define a class for productions
class Production {
public:
  char nonTerminal;       // Non-terminal symbol
  const char *production; // Production rule
  int length;             // Length of the production
};

// Initialize the parse stack and top pointer
StackElement parseStack[MAX_STACK];
int top = -1;

// Define the production rules
Production productions[] = {
    {'S', "AA", 2}, // S -> AA  (production 0)
    {'A', "aA", 2}, // A -> aA  (production 1)
    {'A', "b", 1}   // A -> b   (production 2)
};

// Define the ACTION table
const int ACTION[7][3] = {
    {2, 3, 0},  // State 0
    {0, 0, 1},  // State 1 (Accept)
    {2, 3, 0},  // State 2
    {0, 0, -3}, // State 3 (Reduce A->b)
    {0, 0, -1}, // State 4 (Reduce S->AA)
    {2, 3, 0},  // State 5
    {0, 0, -2}  // State 6 (Reduce A->aA)
};

// Define the GOTO table
const int GOTO[7][2] = {
    {4, 1}, // State 0
    {0, 0}, // State 1
    {6, 0}, // State 2
    {0, 0}, // State 3
    {0, 0}, // State 4
    {0, 0}, // State 5
    {0, 0}  // State 6
};

// Function to get the column index for the action table
int getColumnIndex(char input) {
  switch (input) {
  case 'a':
    return 0;
  case 'b':
    return 1;
  case '$':
    return 2;
  default:
    return -1;
  }
}

// Function to push a state and symbol onto the stack
void push(int state, char symbol) {
  if (top >= MAX_STACK - 1) { // Check for stack overflow
    cout << "Stack overflow\n";
    exit(1);
  }
  parseStack[++top] = {state, symbol}; // Push the element
}

// Function to pop elements from the stack
void pop(int count) {
  top -= count;   // Decrease the top pointer
  if (top < -1) { // Check for stack underflow
    cout << "Stack underflow\n";
    exit(1);
  }
}

// Function to get the string representation of the stack for printing
string getStackString() {
  stringstream ss;
  for (int i = 0; i <= top; i++) {
    ss << "(" << parseStack[i].state << ", " << parseStack[i].symbol << ") ";
  }
  return ss.str();
}

// Function to print the table header
void printTableHeader() {
  cout << "\nAction\tState\tSymbol\tNext State/Production\t\t\tStack\n";
  cout << "---------------------------------------------------------------\n";
}

// Function to parse the input string
int parse(const string &input) {
  int currentPos = 0; // Initialize current position
  push(0, '$');       // Push initial state and symbol
  printTableHeader(); // Print table header

  while (true) {
    char currentInput = input[currentPos];    // Get current input symbol
    int currentState = parseStack[top].state; // Get current state
    int col = getColumnIndex(currentInput); // Get column index for ACTION table

    if (col == -1) { // Check for invalid input symbol
      cout << "Invalid input symbol: " << currentInput << endl;
      return 0;
    }

    int action = ACTION[currentState][col]; // Get action from ACTION table

    // Print action and stack state in table
    if (action == 1 && currentInput == '$') { // Accept condition
      printf("Accept\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
      return 1;
    } else if (action > 0) { // Shift condition
      printf("Shift\t\t%d\t%c\t\t%d\t\t\t\t%s\n", currentState, currentInput,
             action, getStackString().c_str());
      push(action, currentInput);        // Push new state and symbol
      currentPos++;                      // Move to next input symbol
    } else if (action < 0) {             // Reduce condition
      int productionIndex = -action - 1; // Get production index
      Production &prod = productions[productionIndex]; // Get production

      printf("Reduce\t\t%d\t%c\tby production %d\t\t\t%s\n", currentState,
             currentInput, productionIndex, getStackString().c_str());
      pop(prod.length); // Pop elements from stack
      int newState = GOTO[parseStack[top].state]
                         [getColumnIndex(prod.nonTerminal)]; // Get new state
      printf("Goto\t\t\t\t\t\t\t%d\t\t\t\t%s\n", newState,
             getStackString().c_str());
      push(newState, prod.nonTerminal); // Push new state and non-terminal
    } else {                            // Syntax error condition
      cout << "Syntax error at position " << currentPos << endl;
      return 0;
    }
  }
}

// Main function
int main() {
  string input;
  cout << "Enter input string (end with $): "; // Prompt for input
  cin >> input;                                // Read input

  if (parse(input)) { // Parse the input
    cout << "Parsing completed successfully\n";
  } else {
    cout << "Parsing failed\n";
  }
  return 0;
}