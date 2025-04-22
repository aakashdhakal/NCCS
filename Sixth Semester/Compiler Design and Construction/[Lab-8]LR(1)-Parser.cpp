#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Rule {
public:
  char lhs;
  string rhs;

  Rule(char lhs, const string &rhs) : lhs(lhs), rhs(rhs) {}
};

class Parser {
private:
  vector<Rule> rules;
  map<int, map<char, int>> actionTable;
  map<int, map<char, int>> gotoTable;

  void initRules() {
    rules.emplace_back('S', "AB");
    rules.emplace_back('A', "aA");
    rules.emplace_back('A', "");
    rules.emplace_back('B', "bB");
    rules.emplace_back('B', "");
  }

  void initActionTable() {
    actionTable = {{0, {{'a', 1}, {'b', 2}, {'$', -1}}},
                   {1, {{'a', 1}, {'b', -2}, {'$', -2}}},
                   {2, {{'a', -3}, {'b', 2}, {'$', -3}}},
                   {3, {{'a', -1}, {'b', -1}, {'$', 0}}},
                   {4, {{'a', -4}, {'b', -4}, {'$', -4}}}};
  }

  void initGotoTable() {
    gotoTable = {{0, {{'A', 3}, {'B', 4}}},
                 {1, {{'A', 3}, {'B', 4}}},
                 {2, {{'A', 3}, {'B', 4}}},
                 {3, {{'S', 5}, {'A', 3}, {'B', 4}}},
                 {4, {{'A', 3}, {'B', 4}}}};
  }

public:
  Parser() {
    initRules();
    initActionTable();
    initGotoTable();
  }

  bool parse(const string &inputStr) {
    string input = inputStr + "$";
    stack<int> stateStack;
    stack<char> symbolStack;
    stateStack.push(0);
    symbolStack.push('$');

    int i = 0;

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
             << (rule.rhs.empty() ? "ε" : rule.rhs) << endl;

        for (int j = 0; j < rule.rhs.length(); j++) {
          stateStack.pop();
          symbolStack.pop();
        }

        int prevState = stateStack.top();
        int nextState = gotoTable[prevState][rule.lhs];
        stateStack.push(nextState);
        symbolStack.push(rule.lhs);
        cout << "New state after reduction: " << nextState << endl;
      }
    }
  }
};

int main() {
  Parser parser;
  string input;

  cout << "Enter the input string to parse: ";
  getline(cin, input);

  bool result = parser.parse(input);

  if (result) {
    cout << "Accepted" << endl;
  } else {
    cout << "Rejected" << endl;
  }

  return 0;
}
