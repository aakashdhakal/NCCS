#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent a TAC instruction
class TAC {
public:
  string op;
  string arg1;
  string arg2;
  string result;

  TAC(string result, string arg1, string op, string arg2)
      : result(result), arg1(arg1), op(op), arg2(arg2) {}

  void print() {
    if (!op.empty()) {
      cout << result << " = " << arg1 << " " << op << " " << arg2 << endl;
    }
  }
};

// Class to generate TAC instructions from an expression
class TACGenerator {
private:
  vector<TAC> tacList;
  int tempCount = 1;

  string getTempVar() { return "t" + to_string(tempCount++); }

public:
  void generate(string expression) {
    string lastOperand = "";
    string lastOperator = "";

    for (size_t i = 0; i < expression.length(); ++i) {
      if (isalnum(expression[i])) {
        string operand = "";
        while (i < expression.length() && isalnum(expression[i])) {
          operand += expression[i++];
        }
        --i; // Adjust for loop

        if (lastOperand.empty()) {
          lastOperand = operand;
        } else {
          string temp = getTempVar();
          tacList.emplace_back(temp, lastOperand, lastOperator, operand);
          lastOperand = temp;
        }
      } else if (expression[i] == '+' || expression[i] == '-' ||
                 expression[i] == '*' || expression[i] == '/') {
        lastOperator = expression[i];
      }
    }

    // Optional dummy TAC (kept for compatibility with original logic)
    if (!lastOperand.empty()) {
      tacList.emplace_back(lastOperand, lastOperand, "", "0");
    }
  }

  void printTAC() {
    cout << "Three Address Code:\n";
    for (auto &tac : tacList) {
      tac.print();
    }
  }
};

int main() {
  string expr;
  cout << "Enter a simple arithmetic expression (e.g., a + b * c): ";
  getline(cin, expr);

  TACGenerator generator;
  generator.generate(expr);
  generator.printTAC();

  return 0;
}
