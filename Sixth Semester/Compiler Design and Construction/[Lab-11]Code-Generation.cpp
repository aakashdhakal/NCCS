#include <iostream>  // Include the iostream library for input and output
#include <map>       // Include the map library for using map container
#include <stack>     // Include the stack library for using stack container
#include <string>    // Include the string library for using string class

using namespace std; // Use the standard namespace

// Precedence map for operators
map<char, int> precedence = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

// Function to check if a character is an operator
bool isOperator(char c) { return precedence.find(c) != precedence.end(); }

// Function to generate simple assembly-like code for an expression
void generateCode(const string &expr) {
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
            while (!operators.empty() &&
                         precedence[operators.top()] >= precedence[c]) {
                char op = operators.top(); // Get the top operator
                operators.pop();           // Pop the top operator

                string operand2 = operands.top(); // Get the top operand
                operands.pop();                   // Pop the top operand
                string operand1 = operands.top(); // Get the next operand
                operands.pop();                   // Pop the next operand

                string tempVar = "t" + to_string(tempVarCount++); // Create a temporary variable
                operands.push(tempVar); // Push the temporary variable to the operand stack

                // Output the generated code for the operation
                cout << tempVar << " = " << operand1 << " " << op << " " << operand2
                         << endl;
            }
            // Push the current operator to the stack
            operators.push(c);
        }
    }

    // Process remaining operators
    while (!operators.empty()) {
        char op = operators.top(); // Get the top operator
        operators.pop();           // Pop the top operator

        string operand2 = operands.top(); // Get the top operand
        operands.pop();                   // Pop the top operand
        string operand1 = operands.top(); // Get the next operand
        operands.pop();                   // Pop the next operand

        string tempVar = "t" + to_string(tempVarCount++); // Create a temporary variable
        operands.push(tempVar); // Push the temporary variable to the operand stack

        // Output the generated code for the operation
        cout << tempVar << " = " << operand1 << " " << op << " " << operand2
                 << endl;
    }
}

int main() {
    string expr; // Declare a string to store the input expression

    // Take input from the user
    cout << "Enter the arithmetic expression: ";
    cin >> expr;

    // Display the input expression
    cout << "Input Expression: " << expr << endl;
    cout << "Generated Code:" << endl;

    // Generate and display the code
    generateCode(expr);

    return 0; // Return 0 to indicate successful execution
}
