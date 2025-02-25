#include <cctype> // Include cctype for character handling functions
#include <iostream> // Include iostream for input/output operations
#include <unordered_set> // Include unordered_set for efficient keyword lookup

using namespace std; // Use the standard namespace

// Set of C++ reserved keywords for quick lookup
const unordered_set<string> keywords = {
    "int", "float", "double", "char", "return", "if", "else", "while", "for",
    "switch", "case", "default", "break", "continue", "void", "do", "long",
    "short", "signed", "unsigned", "struct", "class", "public",
    "protected", "namespace", "using", "new", "delete", "try",
    "catch", "throw", "static", "const", "volatile", "true",
    "false", "virtual", "this"
};

// Function to check if a string is a keyword
bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end(); // Check if the string is in the set of keywords
}

// Function to check if a string is a valid identifier
bool isValidIdentifier(const string &str) {
    if (str.empty()) // Check if the string is empty
        return false;

    if (!isalpha(str[0]) && str[0] != '_') // First character must be a letter or underscore
        return false;

    for (char ch : str) { // Check remaining characters
        if (!isalnum(ch) && ch != '_') // Must be letters, digits, or underscores
            return false;
    }

    return !isKeyword(str); // Identifier should not be a keyword
}

int main() {
    string input;
    cout << "Enter an identifier: "; // Prompt user for input
    cin >> input; // Read input

    if (isValidIdentifier(input)) { // Check if input is a valid identifier
        cout << "\"" << input << "\" is a valid identifier.\n"; // Print valid message
    } else {
        cout << "\"" << input << "\" is NOT a valid identifier.\n"; // Print invalid message
    }

    return 0; // Return success
}
