#include <iostream> // Include input-output stream library
#include <map>      // Include map library
#include <stack>    // Include stack library
#include <string>   // Include string library
#include <vector>   // Include vector library

using namespace std; // Use the standard namespace

// Define a class for grammar rules
class Rule {
public:
  char lhs;   // Left-hand side of the rule
  string rhs; // Right-hand side of the rule

  Rule(char lhs, string rhs)
      : lhs(lhs), rhs(rhs) {} // Constructor to initialize rule
};

// Define grammar rules
vector<Rule> rules = {Rule('S', "AB"), Rule('A', "aA"), Rule('A', ""),
                      Rule('B', "bB"), Rule('B', "")};

// Define terminal symbols mapping
map<char, int> terminalMap = {{'a', 0}, {'b', 1}, {'$', 2}};

// Define action table for parsing
map<int, map<char, int>> actionTable = {
    {0, {{'a', 1}, {'b', 2}, {'$', -1}}},    // State 0 actions
    {1, {{'a', 1}, {'b', -2}, {'$', -2}}},   // State 1 actions
    {2, {{'a', -3}, {'b', 2}, {'$', -3}}},   // State 2 actions
    {3, {{'a', -1}, {'b', -1}, {'$', 0}}},   // State 3 actions
    {4, {{'a', -4}, {'b', -4}, {'$', -4}}}}; // State 4 actions

// Define goto table for parsing
map<int, map<char, int>> gotoTable = {
    {0, {{'A', 3}, {'B', 4}}},           // State 0 gotos
    {1, {{'A', 3}, {'B', 4}}},           // State 1 gotos
    {2, {{'A', 3}, {'B', 4}}},           // State 2 gotos
    {3, {{'S', 5}, {'A', 3}, {'B', 4}}}, // State 3 gotos
    {4, {{'A', 3}, {'B', 4}}}};          // State 4 gotos

// Function to parse the input string
bool parse(string input) {
  stack<int> stateStack;   // Stack to hold states
  stack<char> symbolStack; // Stack to hold symbols
  stateStack.push(0);      // Push initial state
  symbolStack.push('$');   // Push initial symbol
  int i = 0;
  input += '$'; // Append '$' to input

  while (true) {
    int state = stateStack.top(); // Get current state
    char currentInput = input[i]; // Get current input symbol

    cout << "Current state: " << state << ", Current token: " << currentInput
         << endl;

    // Check if action exists for current state and input
    if (actionTable[state].find(currentInput) == actionTable[state].end()) {
      cout << "Action found: REJECT" << endl;
      return false; // Reject if no action found
    }

    int action = actionTable[state][currentInput]; // Get action

    if (action > 0) { // Shift action
      cout << "Action found: SHIFT to state " << action << endl;
      stateStack.push(action);        // Push new state
      symbolStack.push(currentInput); // Push current input symbol
      i++;                            // Move to next input symbol
    } else if (action == 0) {         // Accept action
      cout << "Action found: ACCEPT" << endl;
      return true;                  // Accept the input
    } else if (action < 0) {        // Reduce action
      int ruleIndex = -action - 1;  // Get rule index
      Rule rule = rules[ruleIndex]; // Get rule
      cout << "Action found: REDUCE using production " << rule.lhs << " -> "
           << rule.rhs << endl;

      // Pop symbols and states based on RHS length
      for (int j = 0; j < rule.rhs.length(); j++) {
        stateStack.pop();
        symbolStack.pop();
      }

      int prevState = stateStack.top(); // Get previous state
      int nextState =
          gotoTable[prevState][rule.lhs]; // Get next state from GOTO table
      stateStack.push(nextState);         // Push next state
      symbolStack.push(rule.lhs);         // Push LHS of rule
      cout << "New state after reduction: " << nextState << endl;
    }
  }
}

int main() {
  string input;
  cout << "Enter input string: ";
  cin >> input;               // Get input string from user
  bool result = parse(input); // Parse the input string

  if (result) {
    cout << "Accepted" << endl; // Print accepted if parsing is successful
  } else {
    cout << "Rejected" << endl; // Print rejected if parsing fails
  }

  return 0;
}
