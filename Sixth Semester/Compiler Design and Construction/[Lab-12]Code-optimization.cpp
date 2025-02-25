#include <iostream> // Include the iostream library for input and output
#include <map> // Include the map library for using map container
#include <stack> // Include the stack library for using stack container
#include <string> // Include the string library for using string class
#include <unordered_map> // Include the unordered_map library for using unordered_map container

using namespace std; // Use the standard namespace

// Precedence map for operators
map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

// To store results of common subexpressions
unordered_map<string, string> optimizationTable;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Return true if the character is an operator
}

// Function to optimize and generate assembly-like code for an expression
void generateOptimizedCode(const string &expr) {
    stack<string> operands; // Stack to store operands
    stack<char> operators;  // Stack to store operators
    int tempVarCount = 1;   // Counter for temporary variables

    // Traverse the expression
    for (char c : expr) {
        if (isdigit(c)) {
            // If the character is a digit, push it as an operand
            operands.push(string(1, c));
        } else if (isOperator(c)) {
            // While top of operator stack has higher precedence, pop it
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                char op = operators.top(); // Get the top operator
                operators.pop(); // Pop the top operator

                string operand2 = operands.top(); // Get the top operand
                operands.pop(); // Pop the top operand
                string operand1 = operands.top(); // Get the next top operand
                operands.pop(); // Pop the next top operand

                string tempVar = "t" + to_string(tempVarCount++); // Create a new temporary variable
                operands.push(tempVar); // Push the temporary variable onto the operand stack

                // Optimization: Common subexpression elimination
                string expression = operand1 + " " + string(1, op) + " " + operand2; // Form the expression
                if (optimizationTable.find(expression) != optimizationTable.end()) {
                    cout << tempVar << " = " << optimizationTable[expression] << endl; // Output the optimized code
                } else {
                    cout << tempVar << " = " << operand1 << " " << op << " " << operand2 << endl; // Output the code
                    optimizationTable[expression] = tempVar; // Store result for future reuse
                }
            }
            operators.push(c); // Push the current operator onto the operator stack
        }
    }

    // Process remaining operators
    while (!operators.empty()) {
        char op = operators.top(); // Get the top operator
        operators.pop(); // Pop the top operator

        string operand2 = operands.top(); // Get the top operand
        operands.pop(); // Pop the top operand
        string operand1 = operands.top(); // Get the next top operand
        operands.pop(); // Pop the next top operand

        string tempVar = "t" + to_string(tempVarCount++); // Create a new temporary variable
        operands.push(tempVar); // Push the temporary variable onto the operand stack

        // Optimization: Common subexpression elimination
        string expression = operand1 + " " + string(1, op) + " " + operand2; // Form the expression
        if (optimizationTable.find(expression) != optimizationTable.end()) {
            cout << tempVar << " = " << optimizationTable[expression] << endl; // Output the optimized code
        } else {
            cout << tempVar << " = " << operand1 << " " << op << " " << operand2 << endl; // Output the code
            optimizationTable[expression] = tempVar; // Store result for future reuse
        }
    }
}

int main() {
    string expr; // Declare a string to store the input expression

    // Take input from the user
    cout << "Enter the arithmetic expression: "; // Prompt the user to enter an expression
    cin >> expr; // Read the input expression

    cout << "Input Expression: " << expr << endl; // Output the input expression
    cout << "Generated Optimized Code:" << endl; // Output the header for the optimized code

    generateOptimizedCode(expr); // Call the function to generate optimized code

    return 0; // Return 0 to indicate successful execution
}
