#include <cctype>    // For character handling functions
#include <iostream>  // For input-output stream
#include <string>    // For string handling

using namespace std;

// List of keywords
const string keywords[] = {
    "int", "float", "double", "char", "return", "if", "else", "while", "for", "switch", "case", "default",
    "break", "continue", "void", "do", "long", "short", "signed", "unsigned", "struct", "class", "public",
    "private", "protected", "namespace", "using", "new", "delete", "try", "catch", "throw", "static", "const",
    "volatile", "true", "false", "virtual", "this"
};

// Operators
const string operators = "+-*/%=!<>|&";

// Separators
const string separators = "();{}[],.";

// Function to check if a word is a keyword
bool isKeyword(const string &str) {
    for (const string &keyword : keywords) { // Iterate through keywords
        if (str == keyword) return true;     // Check if the word matches any keyword
    }
    return false;                            // Return false if no match found
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return operators.find(ch) != string::npos; // Check if character is in operators string
}

// Function to check if a character is a separator
bool isSeparator(char ch) {
    return separators.find(ch) != string::npos; // Check if character is in separators string
}

// Function to check if a word is an identifier
bool isIdentifier(const string &str) {
    if (str.empty() || isdigit(str[0]) || isKeyword(str)) return false; // Check if empty, starts with digit, or is a keyword
    for (char ch : str) { // Iterate through characters
        if (!isalnum(ch) && ch != '_') return false; // Check if character is alphanumeric or underscore
    }
    return true; // Return true if all checks pass
}

// Function to check if a word is a number
bool isNumber(const string &str) {
    for (char ch : str) { // Iterate through characters
        if (!isdigit(ch)) return false; // Check if character is a digit
    }
    return true; // Return true if all characters are digits
}

// Function to perform lexical analysis
void lexicalAnalysis(const string &input) {
    string token = ""; // Initialize token string

    for (size_t i = 0; i < input.length(); i++) { // Iterate through input characters
        char ch = input[i]; // Get current character

        // If whitespace, separator, or operator, process the current token
        if (isspace(ch) || isSeparator(ch) || isOperator(ch)) {
            if (!token.empty()) { // If token is not empty
                if (isKeyword(token)) {
                    cout << "[Keyword]      : " << token << endl;
                } else if (isNumber(token)) {
                    cout << "[Number]       : " << token << endl;
                } else if (isIdentifier(token)) {
                    cout << "[Identifier]   : " << token << endl;
                } else {
                    cout << "[Unknown]      : " << token << endl;
                }
                token = ""; // Reset token
            }

            // Process separators
            if (isSeparator(ch)) {
                cout << "[Separator]    : " << ch << endl;
            }

            // Process operators
            if (isOperator(ch)) {
                string op(1, ch); // Initialize operator string with current character
                // Handle double-character operators (like "==", "!=")
                if (i + 1 < input.length() && isOperator(input[i + 1])) {
                    op += input[++i]; // Append next character to operator and increment index
                }
                cout << "[Operator]     : " << op << endl;
            }
        } else {
            token += ch; // Append character to token
        }
    }

    // Process any remaining token
    if (!token.empty()) {
        if (isKeyword(token)) {
            cout << "[Keyword]      : " << token << endl;
        } else if (isNumber(token)) {
            cout << "[Number]       : " << token << endl;
        } else if (isIdentifier(token)) {
            cout << "[Identifier]   : " << token << endl;
        } else {
            cout << "[Unknown]      : " << token << endl;
        }
    }
}

int main() {
    string input; // Initialize input string
    cout << "Enter a C++ statement: ";
    getline(cin, input); // Get input from user

    cout << "\nLexical Analysis Output:\n";
    lexicalAnalysis(input); // Perform lexical analysis

    return 0; // Return success
}
