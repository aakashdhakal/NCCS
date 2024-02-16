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
    if (str.length() % 2 == 0 || str[str.length() / 2] != 'c')
    {
        cout << "Not accepted" << endl;
        return 0;
    }
    else
    {
        while (str[i] != 'c')
        {
            s.push(str[i]);
            i++;
        }
        i++;
        while (str[i] != '\0')
        {
            if (str[i] != s.pop())
            {
                cout << "Not accepted" << endl;
                return 0;
            }
            i++;
        }
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
