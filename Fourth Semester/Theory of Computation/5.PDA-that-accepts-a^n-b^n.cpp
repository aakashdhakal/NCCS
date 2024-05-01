#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int top;
    char arr[100];

public:
    Stack()
    {
        top = -1;
    }
    void push(char x)
    {
        arr[++top] = x;
    }
    void pop()
    {
        if (!isEmpty())
            top--;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    char peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            return ' ';
    }
};

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    Stack s;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '0' && (s.isEmpty() || s.peek() == '0'))
        {
            s.push('0');
        }
        else if (str[i] == '1' && (s.isEmpty() || s.peek() == '1'))
        {
            s.push('1');
        }
        else if (str[i] == '0' && s.peek() == '1')
        {
            s.pop();
        }
        else if (str[i] == '1' && s.peek() == '0')
        {
            s.pop();
        }
        else
        {
            cout << "Not Accepted" << endl;
            return 0;
        }
        i++;
    }
    if (s.isEmpty())
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "No Accepted" << endl;
    }
    return 0;
}
