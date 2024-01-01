#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string str; // Declare a string to hold the input
    int l;      // Declare an integer to hold the length of the string

    cout << "Enter a string: "; // Prompt the user to enter a string
    cin >> str;                 // Read the string from the user
    l = str.length();           // Get the length of the string

    // Print all prefixes of the string
    cout << "\nPrefix: ";
    for (int i = 0; i < l; i++)
    {
        // Use substr to get the prefix ending at position i
        cout << str.substr(0, i + 1) << " ";
    }
    cout << endl;

    // Print all suffixes of the string
    cout << "\nSuffix: ";
    for (int i = 0; i < l; i++)
    {
        // Use substr to get the suffix starting at position i
        cout << str.substr(i, l - i) << " ";
    }
    cout << endl;

    // Print all unique substrings of the string
    cout << "\nSubstring: ";
    set<string> unique_substrings; // Use a set to keep track of unique substrings
    for (int i = 0; i < l; i++)
    {
        for (int j = i; j < l; j++)
        {
            // Extract substring using string.substr() function
            string sub = str.substr(i, j - i + 1); // (start, length) of substring
            // Check if substring has already been generated
            if (unique_substrings.find(sub) == unique_substrings.end())
            {
                unique_substrings.insert(sub); // If not, insert it into the set
                cout << sub << " ";            // And print it
            }
        }
    }
    cout << endl;
    cin.get();
    return 0;
}
