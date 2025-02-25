#include <iostream> // Include input-output stream library
#include <sstream>  // Include string stream library
#include <vector>   // Include vector container library

using namespace std; // Use the standard namespace

class ThreeAddressCode {
private:
  int tempCount;       // Counter for temporary variables
  vector<string> code; // Vector to store the generated code

public:
  ThreeAddressCode()
      : tempCount(0) {} // Constructor initializing tempCount to 0

  // Function to generate a new temporary variable name
  string generateTemp() { return "t" + to_string(tempCount++); }

  // Function to generate three-address code for an expression
  void generateTAC(const string &op, const string &operand1,
                   const string &operand2) {
    string temp = generateTemp(); // Generate a new temporary variable
    code.push_back(temp + " = " + operand1 + " " + op + " " +
                   operand2); // Create and store the TAC statement
  }

  // Function to print the generated TAC
  void printTAC() const {
    for (const string &statement : code) { // Iterate through the code vector
      cout << statement << endl;           // Print each statement
    }
  }

  // Function to process user input and generate TAC
  void processInput() {
    string expression;
    cout
        << "Enter arithmetic expression in format (operand operator operand): ";
    getline(cin, expression); // Get the entire input line

    stringstream ss(expression); // Create a string stream from the input
    string operand1, operand2, op;
    ss >> operand1 >> op >>
        operand2; // Parse the input into operands and operator

    generateTAC(op, operand1,
                operand2); // Generate the TAC for the given expression
  }
};

int main() {
  ThreeAddressCode tac; // Create an instance of ThreeAddressCode

  char cont = 'y'; // Variable to control the loop
  while (cont == 'y' ||
         cont == 'Y') { // Loop to keep accepting inputs from the user
    tac.processInput(); // Process user input and generate TAC
    cout << "\nGenerated Three Address Code:\n";
    tac.printTAC(); // Print the generated TAC

    cout << "\nDo you want to enter another expression? (y/n): ";
    cin >> cont;  // Ask user if they want to continue
    cin.ignore(); // Discard the newline character left by cin
  }

  return 0; // Return 0 to indicate successful execution
}
