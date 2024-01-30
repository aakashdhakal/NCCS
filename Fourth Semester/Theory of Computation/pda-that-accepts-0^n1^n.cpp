#include <iostream>
#include <stack>

#define MAX 100

class Stack {
public:
    char items[MAX];
    int top;

    void push(char value) {
        items[++top] = value;
    }

    char pop() {
        return items[top--];
    }

    bool is_empty() {
        return (top == -1);
    }
};

int main() {
    char input[MAX];
    Stack stk;
    stk.top = -1;
    int i = 0;

    std::cout << "Enter the string: ";
    std::cin >> input;

    // Push 'Z' onto the stack
    stk.push('Z');

    // Traverse the input string
    while (input[i]) {
        if (input[i] == '0') {
            stk.push('0');
        } else if (input[i] == '1') {
            if (stk.is_empty()) {
                std::cout << "Rejected\n";
                return 0;
            } else {
                stk.pop();
            }
        } else {
            std::cout << "Invalid input\n";
            return 0;
        }
        i++;
    }

    if (stk.is_empty() || (stk.items[stk.top] == 'Z' && stk.top == 0)) {
        std::cout << "Accepted\n";
    } else {
        std::cout << "Rejected\n";
    }

    return 0;
}
