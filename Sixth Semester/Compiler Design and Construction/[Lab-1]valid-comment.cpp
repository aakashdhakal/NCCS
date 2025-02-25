#include <iostream> // Include the iostream library for input and output
#include <string> // Include the string library for string manipulation

using namespace std; // Use the standard namespace

// Function to check if a string is within a comment
bool isWithinComment(const string &str) {
  // Check for single-line comment
  if (str.find("//") != string::npos) { // If '//' is found in the string
    return true; // Return true indicating it's a single-line comment
  }

  // Check for multi-line comment
  size_t multiStart = str.find("/*"); // Find the start of a multi-line comment
  size_t multiEnd = str.find("*/"); // Find the end of a multi-line comment

  // If the start of a multi-line comment is found and the end is not found or comes after the start
  if (multiStart != string::npos && (multiEnd == string::npos || multiEnd > multiStart)) {
    return true; // Return true indicating it's within a multi-line comment
  }

  return false; // Return false if no comment is found
}

int main() {
  string input; // Declare a string to hold user input
  cout << "Enter a string: "; // Prompt the user to enter a string
  getline(cin, input); // Get the entire line of input from the user

  // Check if the input string is within a comment
  if (isWithinComment(input)) {
    cout << "The entered string is within a valid comment section.\n"; // Output if the string is within a comment
  } else {
    cout << "The entered string is NOT within a valid comment section.\n"; // Output if the string is not within a comment
  }

  return 0; // Return 0 to indicate successful execution
}
