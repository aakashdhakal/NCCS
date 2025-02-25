#include <cstring> // Include the cstring library for string manipulation functions
#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace

const int MAX_RULES = 10; // Define a constant for the maximum number of production rules
const int MAX_SYMBOLS = 20; // Define a constant for the maximum number of symbols in a rule

char grammar[MAX_RULES][MAX_SYMBOLS]; // Declare a 2D array to store the grammar rules
int numRules; // Declare a variable to store the number of production rules
char firstSets[MAX_RULES][MAX_SYMBOLS]; // Declare a 2D array to store the FIRST sets
char followSets[MAX_RULES][MAX_SYMBOLS]; // Declare a 2D array to store the FOLLOW sets

void computeFirst(char nonTerminal); // Function prototype to compute the FIRST set of a non-terminal
void computeFollow(char nonTerminal); // Function prototype to compute the FOLLOW set of a non-terminal

int main() {
    cout << "Enter the number of production rules: "; // Prompt the user to enter the number of production rules
    cin >> numRules; // Read the number of production rules from the user
    cin.ignore(); // Ignore the newline character left in the input buffer

    cout << "Enter the production rules: " << endl; // Prompt the user to enter the production rules
    for (int i = 0; i < numRules; i++) { // Loop to read each production rule
        cin.getline(grammar[i], MAX_SYMBOLS); // Read a production rule from the user
    }

    memset(firstSets, '\0', sizeof(firstSets)); // Initialize the FIRST sets array with null characters
    memset(followSets, '\0', sizeof(followSets)); // Initialize the FOLLOW sets array with null characters

    for (int i = 0; i < numRules; i++) { // Loop to compute the FIRST and FOLLOW sets for each non-terminal
        computeFirst(grammar[i][0]); // Compute the FIRST set for the non-terminal
        computeFollow(grammar[i][0]); // Compute the FOLLOW set for the non-terminal
    }

    cout << "\nFIRST Sets:" << endl; // Print the FIRST sets
    for (int i = 0; i < numRules; i++) { // Loop to print each FIRST set
        cout << "FIRST(" << grammar[i][0] << ") = { "; // Print the non-terminal
        for (int j = 0; firstSets[i][j] != '\0'; j++) { // Loop to print each symbol in the FIRST set
            cout << firstSets[i][j] << " "; // Print the symbol
        }
        cout << "}" << endl; // Close the set
    }

    cout << "\nFOLLOW Sets:" << endl; // Print the FOLLOW sets
    for (int i = 0; i < numRules; i++) { // Loop to print each FOLLOW set
        cout << "FOLLOW(" << grammar[i][0] << ") = { "; // Print the non-terminal
        for (int j = 0; followSets[i][j] != '\0'; j++) { // Loop to print each symbol in the FOLLOW set
            cout << followSets[i][j] << " "; // Print the symbol
        }
        cout << "}" << endl; // Close the set
    }

    return 0; // Return 0 to indicate successful execution
}

void computeFirst(char nonTerminal) {
    int index = -1; // Initialize the index to -1
    for (int i = 0; i < numRules; i++) { // Loop to find the index of the non-terminal in the grammar
        if (grammar[i][0] == nonTerminal) { // Check if the current rule's non-terminal matches the given non-terminal
            index = i; // Set the index to the current rule's index
            break; // Break the loop
        }
    }
    if (index == -1) return; // If the non-terminal is not found, return

    for (int i = 3; grammar[index][i] != '\0'; i++) { // Loop to process the production rule
        char currentSymbol = grammar[index][i]; // Get the current symbol in the production rule
        if (isupper(currentSymbol)) { // Check if the current symbol is a non-terminal
            computeFirst(currentSymbol); // Recursively compute the FIRST set for the non-terminal
            for (int j = 0; j < numRules; j++) { // Loop to find the FIRST set of the non-terminal
                if (grammar[j][0] == currentSymbol) { // Check if the current rule's non-terminal matches the current symbol
                    for (int k = 0; firstSets[j][k] != '\0'; k++) { // Loop to add the symbols from the FIRST set
                        if (!strchr(firstSets[index], firstSets[j][k])) { // Check if the symbol is not already in the FIRST set
                            int len = strlen(firstSets[index]); // Get the length of the FIRST set
                            firstSets[index][len] = firstSets[j][k]; // Add the symbol to the FIRST set
                            firstSets[index][len + 1] = '\0'; // Null-terminate the FIRST set
                        }
                    }
                    break; // Break the loop
                }
            }
            if (!strchr(firstSets[index], 'e')) break; // If epsilon is not in the FIRST set, break the loop
        } else { // If the current symbol is a terminal
            if (!strchr(firstSets[index], currentSymbol)) { // Check if the symbol is not already in the FIRST set
                int len = strlen(firstSets[index]); // Get the length of the FIRST set
                firstSets[index][len] = currentSymbol; // Add the symbol to the FIRST set
                firstSets[index][len + 1] = '\0'; // Null-terminate the FIRST set
            }
            break; // Break the loop
        }
    }
}

void computeFollow(char nonTerminal) {
    int index = -1; // Initialize the index to -1
    for (int i = 0; i < numRules; i++) { // Loop to find the index of the non-terminal in the grammar
        if (grammar[i][0] == nonTerminal) { // Check if the current rule's non-terminal matches the given non-terminal
            index = i; // Set the index to the current rule's index
            break; // Break the loop
        }
    }
    if (index == -1) return; // If the non-terminal is not found, return

    if (nonTerminal == grammar[0][0] && !strchr(followSets[index], '$')) { // If the non-terminal is the start symbol and '$' is not in the FOLLOW set
        int len = strlen(followSets[index]); // Get the length of the FOLLOW set
        followSets[index][len] = '$'; // Add '$' to the FOLLOW set
        followSets[index][len + 1] = '\0'; // Null-terminate the FOLLOW set
    }

    for (int i = 0; i < numRules; i++) { // Loop to process each production rule
        for (int j = 3; grammar[i][j] != '\0'; j++) { // Loop to find the non-terminal in the production rule
            if (grammar[i][j] == nonTerminal) { // Check if the current symbol matches the non-terminal
                if (grammar[i][j + 1] != '\0') { // If there is a symbol after the non-terminal
                    char nextSymbol = grammar[i][j + 1]; // Get the next symbol
                    if (isupper(nextSymbol)) { // Check if the next symbol is a non-terminal
                        for (int k = 0; k < numRules; k++) { // Loop to find the FIRST set of the next symbol
                            if (grammar[k][0] == nextSymbol) { // Check if the current rule's non-terminal matches the next symbol
                                for (int l = 0; firstSets[k][l] != '\0'; l++) { // Loop to add the symbols from the FIRST set
                                    if (!strchr(followSets[index], firstSets[k][l])) { // Check if the symbol is not already in the FOLLOW set
                                        int len = strlen(followSets[index]); // Get the length of the FOLLOW set
                                        followSets[index][len] = firstSets[k][l]; // Add the symbol to the FOLLOW set
                                        followSets[index][len + 1] = '\0'; // Null-terminate the FOLLOW set
                                    }
                                }
                            }
                        }
                    } else { // If the next symbol is a terminal
                        if (!strchr(followSets[index], nextSymbol)) { // Check if the symbol is not already in the FOLLOW set
                            int len = strlen(followSets[index]); // Get the length of the FOLLOW set
                            followSets[index][len] = nextSymbol; // Add the symbol to the FOLLOW set
                            followSets[index][len + 1] = '\0'; // Null-terminate the FOLLOW set
                        }
                    }
                } else if (grammar[i][0] != nonTerminal) { // If the non-terminal is at the end of the production rule
                    computeFollow(grammar[i][0]); // Recursively compute the FOLLOW set for the non-terminal on the left-hand side
                    for (int k = 0; followSets[i][k] != '\0'; k++) { // Loop to add the symbols from the FOLLOW set
                        if (!strchr(followSets[index], followSets[i][k])) { // Check if the symbol is not already in the FOLLOW set
                            int len = strlen(followSets[index]); // Get the length of the FOLLOW set
                            followSets[index][len] = followSets[i][k]; // Add the symbol to the FOLLOW set
                            followSets[index][len + 1] = '\0'; // Null-terminate the FOLLOW set
                        }
                    }
                }
            }
        }
    }
}
