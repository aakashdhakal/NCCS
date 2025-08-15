#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct Rule {
  char lhs;
  string rhs;
};

vector<Rule> rules = {
    {'S', "AB"}, {'A', "aA"}, {'A', ""}, {'B', "bB"}, {'B', ""}};

map<char, int> terminalMap = {{'a', 0}, {'b', 1}, {'$', 2}};

map<int, map<char, int>> actionTable = {{0, {{'a', 1}, {'b', 2}, {'$', -1}}},
                                        {1, {{'a', 1}, {'b', -2}, {'$', -2}}},
                                        {2, {{'a', -3}, {'b', 2}, {'$', -3}}},
                                        {3, {{'a', -1}, {'b', -1}, {'$', 0}}},
                                        {4, {{'a', -4}, {'b', -4}, {'$', -4}}}};

map<int, map<char, int>> gotoTable = {{0, {{'A', 3}, {'B', 4}}},
                                      {1, {{'A', 3}, {'B', 4}}},
                                      {2, {{'A', 3}, {'B', 4}}},
                                      {3, {{'S', 5}, {'A', 3}, {'B', 4}}},
                                      {4, {{'A', 3}, {'B', 4}}}};

bool parse(string input) {
  stack<int> stateStack;
  stack<char> symbolStack;
  stateStack.push(0);
  symbolStack.push('$'); // Push initial symbol
  int i = 0;
  input += '$'; // Append '$' to input

  while (true) {
    int state = stateStack.top();
    char currentInput = input[i];

    cout << "Current state: " << state << ", Current token: " << currentInput
         << endl;

    if (actionTable[state].find(currentInput) == actionTable[state].end()) {
      cout << "Action found: REJECT" << endl;
      return false;
    }

    int action = actionTable[state][currentInput];

    if (action > 0) {
      cout << "Action found: SHIFT to state " << action << endl;
      stateStack.push(action);
      symbolStack.push(currentInput);
      i++;
    } else if (action == 0) {
      cout << "Action found: ACCEPT" << endl;
      return true;
    } else if (action < 0) {
      int ruleIndex = -action - 1;
      Rule rule = rules[ruleIndex];
      cout << "Action found: REDUCE using production " << rule.lhs << " -> "
           << rule.rhs << endl;

      // Pop symbols and states based on RHS length
      for (int j = 0; j < rule.rhs.length(); j++) {
        stateStack.pop();
        symbolStack.pop();
      }

      // Get the state *before* the pop
      int prevState = stateStack.top();

      // Use prevState to get the next state from the GOTO table
      int nextState = gotoTable[prevState][rule.lhs];
      stateStack.push(nextState);
      symbolStack.push(rule.lhs);
      cout << "New state after reduction: " << nextState << endl;
    }
  }
}

int main() {
  string input;
  cout << "Enter input string :";
  cin >> input;
  bool result = parse(input);

  if (result) {
    cout << "Accepted" << endl;
  } else {
    cout << "Rejected" << endl;
  }

  return 0;
}