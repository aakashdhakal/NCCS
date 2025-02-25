#include <cstring> // Include the C string library for string manipulation functions
#include <iostream> // Include the C++ standard input-output stream library

using namespace std; // Use the standard namespace

#define MAX_RULES 10 // Define the maximum number of grammar rules
#define MAX_SYMBOLS 10 // Define the maximum number of symbols in a rule
#define MAX_TERMINALS 10 // Define the maximum number of terminal symbols
#define MAX_NON_TERMINALS 10 // Define the maximum number of non-terminal symbols

// Grammar rules
char grammar[MAX_RULES][MAX_SYMBOLS]; // Array to store grammar rules

// FIRST and FOLLOW sets for each non-terminal
char first[MAX_NON_TERMINALS][MAX_TERMINALS]; // Array to store FIRST sets
char follow[MAX_NON_TERMINALS][MAX_TERMINALS]; // Array to store FOLLOW sets

// Terminal and Non-Terminal arrays
char nonTerminals[MAX_NON_TERMINALS]; // Array to store non-terminal symbols
char terminals[MAX_TERMINALS]; // Array to store terminal symbols, $ is the end-of-input marker

int ruleCount = 0; // Number of grammar rules
int ntCount = 0; // Number of non-terminals
int tCount = 0; // Number of terminals

// Function to check if a character is a terminal
bool isTerminal(char ch) {
    return !(ch >= 'A' && ch <= 'Z'); // Terminals are lowercase or special symbols
}

// Function to add a character to a set (array)
void addToSet(char set[][MAX_TERMINALS], int index, char ch) {
    for (int i = 0; set[index][i] != '\0'; i++) { // Check if character is already in the set
        if (set[index][i] == ch) return; // Avoid duplicates
    }
    int len = strlen(set[index]); // Get the current length of the set
    set[index][len] = ch; // Add the character to the set
    set[index][len + 1] = '\0'; // Null-terminate the set
}

// Function to find the index of a non-terminal
int findIndex(char ch, char symbols[], int count) {
    for (int i = 0; i < count; i++) { // Iterate through the symbols array
        if (symbols[i] == ch) return i; // Return the index if found
    }
    return -1; // Return -1 if not found
}

// Compute the FIRST sets
void computeFirst() {
    for (int i = 0; i < ntCount; i++) { // Iterate through non-terminals
        char symbol = nonTerminals[i]; // Get the current non-terminal
        for (int j = 0; j < ruleCount; j++) { // Iterate through grammar rules
            if (grammar[j][0] == symbol) { // Check if the rule's LHS matches the non-terminal
                char firstSymbol = grammar[j][3]; // First symbol after "->"
                if (isTerminal(firstSymbol)) { // Check if the first symbol is a terminal
                    addToSet(first, i, firstSymbol); // Add the terminal to the FIRST set
                } else { // If the first symbol is a non-terminal
                    int idx = findIndex(firstSymbol, nonTerminals, ntCount); // Find the index of the non-terminal
                    for (int k = 0; first[idx][k] != '\0'; k++) { // Iterate through the FIRST set of the non-terminal
                        addToSet(first, i, first[idx][k]); // Add each symbol to the current non-terminal's FIRST set
                    }
                }
            }
        }
    }
}

// Compute the FOLLOW sets
void computeFollow() {
    follow[0][0] = '$'; // Start symbol FOLLOW set includes '$'
    follow[0][1] = '\0'; // Null-terminate the set

    for (int i = 0; i < ntCount; i++) { // Iterate through non-terminals
        char symbol = nonTerminals[i]; // Get the current non-terminal
        for (int j = 0; j < ruleCount; j++) { // Iterate through grammar rules
            for (int k = 3; grammar[j][k] != '\0'; k++) { // Iterate through symbols in the rule
                if (grammar[j][k] == symbol) { // Check if the symbol matches the non-terminal
                    if (grammar[j][k + 1] != '\0') { // Check if there is a next symbol
                        char nextSymbol = grammar[j][k + 1]; // Get the next symbol
                        if (isTerminal(nextSymbol)) { // Check if the next symbol is a terminal
                            addToSet(follow, i, nextSymbol); // Add the terminal to the FOLLOW set
                        } else { // If the next symbol is a non-terminal
                            int idx = findIndex(nextSymbol, nonTerminals, ntCount); // Find the index of the non-terminal
                            for (int m = 0; first[idx][m] != '\0'; m++) { // Iterate through the FIRST set of the non-terminal
                                if (first[idx][m] != '#') { // Check if the symbol is not epsilon
                                    addToSet(follow, i, first[idx][m]); // Add the symbol to the FOLLOW set
                                }
                            }
                        }
                    } else { // If there is no next symbol
                        int idx = findIndex(grammar[j][0], nonTerminals, ntCount); // Find the index of the rule's LHS non-terminal
                        for (int m = 0; follow[idx][m] != '\0'; m++) { // Iterate through the FOLLOW set of the LHS non-terminal
                            addToSet(follow, i, follow[idx][m]); // Add each symbol to the current non-terminal's FOLLOW set
                        }
                    }
                }
            }
        }
    }
}

// Function to fill the Parsing Table
void fillParsingTable(char parsingTable[][MAX_TERMINALS][MAX_RULES]) {
    for (int i = 0; i < ntCount; i++) { // Iterate through non-terminals
        for (int j = 0; j < ruleCount; j++) { // Iterate through grammar rules
            if (grammar[j][0] == nonTerminals[i]) { // Check if the rule's LHS matches the non-terminal
                char firstSymbol = grammar[j][3]; // First symbol after "->"
                int idx = findIndex(firstSymbol, terminals, tCount); // Find the index of the terminal

                if (idx != -1) { // Check if the terminal is found
                    strcpy(parsingTable[i][idx], grammar[j]); // Fill the parsing table with the production
                }

                if (firstSymbol == '#') { // Check if the first symbol is epsilon
                    int followIdx = findIndex(nonTerminals[i], nonTerminals, ntCount); // Find the index of the non-terminal
                    for (int k = 0; follow[followIdx][k] != '\0'; k++) { // Iterate through the FOLLOW set of the non-terminal
                        int terminalIdx = findIndex(follow[followIdx][k], terminals, tCount); // Find the index of the terminal
                        if (terminalIdx != -1) { // Check if the terminal is found
                            strcpy(parsingTable[i][terminalIdx], grammar[j]); // Fill the parsing table with the production
                        }
                    }
                }
            }
        }
    }
}

// Function to display the Parsing Table
void displayParsingTable(char parsingTable[][MAX_TERMINALS][MAX_RULES]) {
    cout << "\nParsing Table:\n\t"; // Print the header for the parsing table
    for (int j = 0; j < tCount; j++) { // Iterate through terminals
        cout << terminals[j] << "\t"; // Display terminal symbols as column headers
    }
    cout << endl;

    for (int i = 0; i < ntCount; i++) { // Iterate through non-terminals
        cout << nonTerminals[i] << "\t"; // Display non-terminal symbols as row headers
        for (int j = 0; j < tCount; j++) { // Iterate through terminals
            if (parsingTable[i][j][0] != '\0') { // Check if there is a production rule
                cout << parsingTable[i][j] << "\t"; // Display the production rule
            } else {
                cout << "\t"; // Display an empty cell
            }
        }
        cout << endl;
    }
}

int main() {
    // Take the number of rules as input
    cout << "Enter the number of grammar rules: ";
    cin >> ruleCount;

    // Input the grammar rules
    cout << "Enter the production rules: " << endl;
    for (int i = 0; i < ruleCount; i++) {
        cin >> grammar[i];
    }

    // Identify non-terminals and terminals from grammar
    for (int i = 0; i < ruleCount; i++) {
        char lhs = grammar[i][0];
        if (findIndex(lhs, nonTerminals, ntCount) == -1) { // Check if the non-terminal is not already in the array
            nonTerminals[ntCount++] = lhs; // Add the non-terminal to the array
        }

        for (int j = 3; grammar[i][j] != '\0'; j++) { // Iterate through symbols in the rule
            if (isTerminal(grammar[i][j]) && findIndex(grammar[i][j], terminals, tCount) == -1) { // Check if the symbol is a terminal and not already in the array
                terminals[tCount++] = grammar[i][j]; // Add the terminal to the array
            }
        }
    }

    // Add the $ symbol to the terminals (end-of-input marker)
    terminals[tCount++] = '$';

    // Compute FIRST and FOLLOW sets
    computeFirst();
    computeFollow();

    // Initialize the parsing table
    char parsingTable[MAX_NON_TERMINALS][MAX_TERMINALS][MAX_RULES] = {};

    // Fill the parsing table based on FIRST and FOLLOW sets
    fillParsingTable(parsingTable);

    // Display the parsing table
    displayParsingTable(parsingTable);

    return 0;
}
