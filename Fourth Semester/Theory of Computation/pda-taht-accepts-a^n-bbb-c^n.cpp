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
    char peek()
    {
        return arr[top];
    }
};

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    Stack s;
    int i = 0;
    int countB = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'a')
        {
            s.push(str[i]);
        }
        else if (str[i] == 'b')
        {
            cout << countB << endl;
            if (s.isEmpty() || s.peek() != 'a')
            {
                cout << "Not Accepted" << endl;
                return 0;
            }
            else if (countB < 3)
            {
                countB++;
            }
            else
            {
                cout << "Not Accepted" << endl;
                return 0;
            }
        }
        else if (str[i] == 'c')
        {
            if (s.isEmpty() || s.peek() != 'a')
            {
                cout << "Not Accepted" << endl;
                return 0;
            }
            else
                s.pop();
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
