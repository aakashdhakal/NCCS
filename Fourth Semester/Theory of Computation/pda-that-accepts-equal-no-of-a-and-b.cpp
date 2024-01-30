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
    char pop()
    {
        return arr[top--];
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    Stack s;
    int i = 0;
    char ch1, ch2;

    if (str[0] == 'a')
    {
        ch1 = 'a';
        ch2 = 'b';
    }
    else
    {
        ch1 = 'b';
        ch2 = 'a';
    }
    while (str[i] != '\0')
    {
        if (str[i] == ch1)
        {
            s.push(str[i]);
        }
        else if (str[i] == ch2)
        {
            if (s.isEmpty())
            {
                cout << "Not accepted" << endl;
                return 0;
            }
            else
            {
                s.pop();
            }
        }
        else
        {
            cout << "Not accepted" << endl;
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
        cout << "Not accepted" << endl;
    }
    return 0;
}