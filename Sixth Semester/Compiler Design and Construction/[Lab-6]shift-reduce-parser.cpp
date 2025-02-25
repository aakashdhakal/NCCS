#include <cstring>  // Include cstring for string handling functions
#include <iostream> // Include iostream for input/output operations
#include <vector>   // Include vector for dynamic arrays
using namespace std;

// Global Variables
int i = 0, j = 0;
char a[50], stk[50];
vector<pair<string, string>> rules; // Stores production rules (left -> right)

// Function to check if any production rule can be applied to the stack
void check() {
  // Iterate over each production rule
  for (const auto &rule : rules) {
    string left = rule.first; // Left-hand side of the production (Non-terminal)
    string right =
        rule.second; // Right-hand side of the production (Replacement)

    // Ensure the stack is long enough to apply the rule
    if (strlen(stk) >= right.length() &&
        string(stk).substr(strlen(stk) - right.length()) == right) {
      // Print the reduction action
      printf("REDUCE TO %s->%s", left.c_str(), right.c_str());

      // Update the stack after reduction
      string new_stack =
          string(stk).substr(0, strlen(stk) - right.length()) + left;
      strcpy(stk, new_stack.c_str());

      // Print the current stack and input
      printf("\n$%s\t%s$\t", stk, a);
    }
  }
}

// Driver Function
int main() {
  // Grammar input
  cout << "Enter grammar rules (in the format: Non-terminal->Production, type "
          "'done' to stop):\n";
  string grammar;

  // Read grammar rules from user
  while (true) {
    cout << "Enter a production rule: ";
    getline(cin, grammar);
    if (grammar == "done")
      break;

    // Split the production rule into left-hand side (Non-terminal) and
    // right-hand side (Production)
    size_t pos = grammar.find("->");
    if (pos != string::npos) {
      string left = grammar.substr(0, pos);
      string right = grammar.substr(pos + 2);
      rules.push_back({left, right});
    }
  }

  // Output grammar
  cout << "\nGrammar is:\n";
  for (const auto &rule : rules) {
    cout << rule.first << "->" << rule.second << "\n";
  }

  // Input string
  cout << "\nEnter the string to be parsed: ";
  cin >> a;

  // Initial action
  printf("\nstack \t input \t action");
  printf("\n$\t%s$\t", a);

  // Parsing the input string
  for (j = 0; a[j] != '\0'; j++) {
    // Print the shift action
    printf("SHIFT");

    // Push the current character into the stack
    stk[i++] = a[j];
    stk[i] = '\0';

    // Mark the current character as processed
    a[j] = ' ';

    // Print the current stack and input
    printf("\n$%s\t%s$\t", stk, a);

    // Check if any production can be applied
    check();
  }

  // Rechecking one last time for any valid production
  check();

  // If top of the stack is the start symbol (S), then it will accept the input
  if (stk[0] == 'S' && stk[1] == '\0')
    printf("Accept\n");
  else
    printf("Reject\n");

  return 0;
}
