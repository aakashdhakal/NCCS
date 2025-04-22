#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

map<char, int> precedence;
unordered_map<string, string>
    optimizationTable; // To store results of common subexpressions

// Function to check if a character is an operator
bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to optimize and generate assembly-like code for an expression
void generateOptimizedCode(const string &expr) {
  stack<string> operands;
  stack<char> operators;

  // Precedence map for operators
  precedence['+'] = 1;
  precedence['-'] = 1;
  precedence['*'] = 2;
  precedence['/'] = 2;

  int tempVarCount = 1;

  // Traverse the expression
  for (int i = 0; i < expr.length(); i++) {
    char c = expr[i];

    if (isdigit(c)) {
      // If the character is a digit, push it as an operand
      operands.push(string(1, c));
    } else if (isOperator(c)) {
      // While top of operator stack has higher precedence, pop it
      while (!operators.empty() &&
             precedence[operators.top()] >= precedence[c]) {
        char op = operators.top();
        operators.pop();

        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();

        string tempVar = "t" + to_string(tempVarCount++);
        operands.push(tempVar);

        // Optimization: Common subexpression elimination
        string expression = operand1 + " " + string(1, op) + " " + operand2;
        if (optimizationTable.find(expression) != optimizationTable.end()) {
          string optimizedResult = optimizationTable[expression];
          cout << tempVar << " = " << optimizedResult << endl;
        } else {
          cout << tempVar << " = " << operand1 << " " << op << " " << operand2
               << endl;
          optimizationTable[expression] =
              tempVar; // Store result for future reuse
        }
      }
      operators.push(c);
    }
  }

  // Process remaining operators
  while (!operators.empty()) {
    char op = operators.top();
    operators.pop();

    string operand2 = operands.top();
    operands.pop();
    string operand1 = operands.top();
    operands.pop();

    string tempVar = "t" + to_string(tempVarCount++);
    operands.push(tempVar);

    // Optimization: Common subexpression elimination
    string expression = operand1 + " " + string(1, op) + " " + operand2;
    if (optimizationTable.find(expression) != optimizationTable.end()) {
      string optimizedResult = optimizationTable[expression];
      cout << tempVar << " = " << optimizedResult << endl;
    } else {
      cout << tempVar << " = " << operand1 << " " << op << " " << operand2
           << endl;
      optimizationTable[expression] = tempVar;
    }
  }
}

int main() {
  string expr;

  // Take input from the user
  cout << "Enter the arithmetic expression: ";
  cin >> expr;

  cout << "Input Expression: " << expr << endl;
  cout << "Generated Optimized Code:" << endl;

  generateOptimizedCode(expr);

  return 0;
}