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

    if (str.length() % 2 != 0)
    {
        cout << "String rejected" << endl;
        return 0;
    }

    for (int i = 0; i < str.length() / 2; i++)
    {
        s.push(str[i]);
    }

    for (int i = str.length() / 2; i < str.length(); i++)
    {
        if (str[i] == s.peek())
        {
            s.pop();
        }
    }

    if (s.isEmpty())
    {
        cout << "String accepted" << endl;
    }
    else
    {
        cout << "String rejected" << endl;
    }

    return 0;
}
