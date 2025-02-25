#include <iostream> // Include input-output stream library
#include <map>      // Include map library
#include <stack>    // Include stack library
#include <string>   // Include string library
#include <vector>   // Include vector library

using namespace std; // Use the standard namespace

// Rule class to hold grammar rules
class Rule {
public:
  char lhs;   // Left-hand side of the rule
  string rhs; // Right-hand side of the rule

  Rule(char lhs, string rhs)
      : lhs(lhs), rhs(rhs) {} // Constructor to initialize rule
};

// Grammar rules
vector<Rule> rules = {Rule('S', "AB"), Rule('A', "aA"), Rule('A', ""),
                      Rule('B', "bB"), Rule('B', "")};

// Terminal symbols mapping
map<char, int> terminalMap = {{'a', 0}, {'b', 1}, {'$', 2}};

// Action table for LR(1) parsing
map<int, map<char, int>> actionTable = {{0, {{'a', 1}, {'b', 2}, {'$', -1}}},
                                        {1, {{'a', 1}, {'b', -2}, {'$', -2}}},
                                        {2, {{'a', -3}, {'b', 2}, {'$', -3}}},
                                        {3, {{'a', -1}, {'b', -1}, {'$', 0}}},
                                        {4, {{'a', -4}, {'b', -4}, {'$', -4}}}};

// Goto table for LR(1) parsing
map<int, map<char, int>> gotoTable = {{0, {{'A', 3}, {'B', 4}}},
                                      {1, {{'A', 3}, {'B', 4}}},
                                      {2, {{'A', 3}, {'B', 4}}},
                                      {3, {{'S', 5}, {'A', 3}, {'B', 4}}},
                                      {4, {{'A', 3}, {'B', 4}}}};

// Parser class to handle the parsing process
class Parser {
public:
  // Function to parse the input string
  bool parse(const string &input) {
    stack<int> stateStack;               // Stack to hold states
    stack<char> symbolStack;             // Stack to hold symbols
    stateStack.push(0);                  // Push initial state
    symbolStack.push('$');               // Push initial symbol
    int i = 0;                           // Initialize input index
    string augmentedInput = input + '$'; // Append '$' to input

    while (true) {                           // Loop until parsing is complete
      int state = stateStack.top();          // Get current state
      char currentInput = augmentedInput[i]; // Get current input symbol

      cout << "Current state: " << state << ", Current token: " << currentInput
           << endl;

      // If action not found, reject the input
      if (actionTable[state].find(currentInput) == actionTable[state].end()) {
        cout << "Action found: REJECT" << endl;
        return false; // Return false if input is rejected
      }

      int action =
          actionTable[state][currentInput]; // Get action from action table

      if (action > 0) { // Shift action
        cout << "Action found: SHIFT to state " << action << endl;
        stateStack.push(action);        // Push new state
        symbolStack.push(currentInput); // Push current input symbol
        i++;                            // Move to next input symbol
      } else if (action == 0) {         // Accept action
        cout << "Action found: ACCEPT" << endl;
        return true;                  // Return true if input is accepted
      } else if (action < 0) {        // Reduce action
        int ruleIndex = -action - 1;  // Get rule index
        Rule rule = rules[ruleIndex]; // Get rule
        cout << "Action found: REDUCE using production " << rule.lhs << " -> "
             << rule.rhs << endl;

        // Pop symbols and states based on RHS length
        for (int j = 0; j < rule.rhs.length(); j++) {
          stateStack.pop();  // Pop state
          symbolStack.pop(); // Pop symbol
        }

        int prevState = stateStack.top(); // Get previous state
        int nextState =
            gotoTable[prevState][rule.lhs]; // Get next state from goto table
        stateStack.push(nextState);         // Push next state
        symbolStack.push(rule.lhs);         // Push LHS of rule
        cout << "New state after reduction: " << nextState << endl;
      }
    }
  }
};

int main() {
  Parser parser; // Create parser object
  string input;

  cout << "Enter the input string to parse: ";
  getline(cin, input); // Get input string

  bool result = parser.parse(input); // Parse the input string

  if (result) {
    cout << "Accepted" << endl; // If accepted
  } else {
    cout << "Rejected" << endl; // If rejected
  }

  return 0; // Return 0 to indicate successful execution
}