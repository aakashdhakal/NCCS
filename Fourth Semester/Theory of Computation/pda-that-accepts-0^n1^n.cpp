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
    while (str[i] != '\0')
    {
        if (str[i] == '0')
        {
            s.push(str[i]);
        }
        else if (str[i] == '1')
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
