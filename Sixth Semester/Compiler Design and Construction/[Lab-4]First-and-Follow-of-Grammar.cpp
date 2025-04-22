#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int MAX_RULES = 10;
const int MAX_SYMBOLS = 20;
const char EPSILON = 'e'; // Using 'e' for epsilon (empty string)

struct Production {
  char lhs;
  string rhs;
};

vector<Production> grammar;
set<char> nonTerminals;
set<char> terminals;

// Function prototypes
void computeFirstSets();
void computeFollowSets();
set<char> computeFirst(char nonTerminal);
set<char> computeFirstOfString(const string &str);
void printSets();

int main() {
  cout << "Enter the number of production rules: ";
  int numRules;
  cin >> numRules;
  cin.ignore();

  cout << "Enter the production rules (e.g., S->aA|e): " << endl;
  for (int i = 0; i < numRules; i++) {
    string line;
    getline(cin, line);

    size_t arrowPos = line.find("->");
    if (arrowPos == string::npos || arrowPos == 0) {
      cerr << "Invalid rule format: " << line << endl;
      return 1;
    }

    char lhs = line[0];
    string rhs = line.substr(arrowPos + 2);
    nonTerminals.insert(lhs);

    // Split alternatives separated by |
    size_t start = 0;
    size_t end = rhs.find('|');
    while (end != string::npos) {
      string alternative = rhs.substr(start, end - start);
      grammar.push_back({lhs, alternative});

      // Collect terminals
      for (char c : alternative) {
        if (!isupper(c) && c != EPSILON) {
          terminals.insert(c);
        }
      }

      start = end + 1;
      end = rhs.find('|', start);
    }
    string lastAlternative = rhs.substr(start);
    grammar.push_back({lhs, lastAlternative});

    // Collect terminals from last alternative
    for (char c : lastAlternative) {
      if (!isupper(c) && c != EPSILON) {
        terminals.insert(c);
      }
    }
  }

  computeFirstSets();
  computeFollowSets();
  printSets();

  return 0;
}

set<char> computeFirst(char nonTerminal) {
  set<char> first;

  for (const auto &prod : grammar) {
    if (prod.lhs != nonTerminal)
      continue;

    const string &rhs = prod.rhs;
    if (rhs.empty()) {
      first.insert(EPSILON);
      continue;
    }

    bool allProduceEpsilon = true;
    for (char symbol : rhs) {
      if (isupper(symbol)) { // Non-terminal
        set<char> firstOfSymbol = computeFirst(symbol);
        first.insert(firstOfSymbol.begin(), firstOfSymbol.end());
        first.erase(EPSILON);

        if (firstOfSymbol.find(EPSILON) == firstOfSymbol.end()) {
          allProduceEpsilon = false;
          break;
        }
      } else { // Terminal or epsilon
        first.insert(symbol);
        allProduceEpsilon = false;
        break;
      }
    }

    if (allProduceEpsilon) {
      first.insert(EPSILON);
    }
  }

  return first;
}

set<char> computeFirstOfString(const string &str) {
  set<char> first;
  bool allProduceEpsilon = true;

  for (char symbol : str) {
    if (isupper(symbol)) { // Non-terminal
      set<char> firstOfSymbol = computeFirst(symbol);
      first.insert(firstOfSymbol.begin(), firstOfSymbol.end());
      first.erase(EPSILON);

      if (firstOfSymbol.find(EPSILON) == firstOfSymbol.end()) {
        allProduceEpsilon = false;
        break;
      }
    } else { // Terminal or epsilon
      first.insert(symbol);
      allProduceEpsilon = false;
      break;
    }
  }

  if (allProduceEpsilon) {
    first.insert(EPSILON);
  }

  return first;
}

void computeFirstSets() {
  cout << "\nFIRST Sets:" << endl;
  for (char nt : nonTerminals) {
    set<char> first = computeFirst(nt);
    cout << "FIRST(" << nt << ") = { ";
    for (char c : first) {
      cout << c << " ";
    }
    cout << "}" << endl;
  }
}

void computeFollowSets() {
  map<char, set<char>> follow;
  char startSymbol = grammar[0].lhs;
  follow[startSymbol].insert('$'); // Rule 1: $ is in FOLLOW(S)

  bool changed;
  do {
    changed = false;
    for (const auto &prod : grammar) {
      const string &rhs = prod.rhs;
      for (size_t i = 0; i < rhs.size(); i++) {
        char B = rhs[i];
        if (!isupper(B))
          continue; // Only for non-terminals

        // Rule 2: A → αBβ, add FIRST(β)-{ε} to FOLLOW(B)
        string beta = rhs.substr(i + 1);
        if (!beta.empty()) {
          set<char> firstBeta = computeFirstOfString(beta);
          size_t before = follow[B].size();
          follow[B].insert(firstBeta.begin(), firstBeta.end());
          follow[B].erase(EPSILON);
          if (follow[B].size() > before) {
            changed = true;
          }
        }

        // Rule 3: A → αB or A → αBβ where β ⇒* ε
        if (i == rhs.size() - 1 ||
            (beta.empty() ? false
                          : computeFirstOfString(beta).count(EPSILON))) {
          size_t before = follow[B].size();
          follow[B].insert(follow[prod.lhs].begin(), follow[prod.lhs].end());
          if (follow[B].size() > before) {
            changed = true;
          }
        }
      }
    }
  } while (changed);

  cout << "\nFOLLOW Sets:" << endl;
  for (char nt : nonTerminals) {
    cout << "FOLLOW(" << nt << ") = { ";
    for (char c : follow[nt]) {
      cout << c << " ";
    }
    cout << "}" << endl;
  }
}

void printSets() {
  // Already printed in computeFirstSets and computeFollowSets
}