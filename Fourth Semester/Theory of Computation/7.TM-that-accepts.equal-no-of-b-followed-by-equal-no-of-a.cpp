#include <iostream>
using namespace std;

int head = 0;

void right()
{
    head++;
}

void left()
{
    head--;
}

int main()
{
    string A;
    int state = 0;
    cout << "Enter a string: ";
    cin >> A;
    while (true)
    {
        if (state == 0 && A[head] == 'b')
        {
            A[head] = 'X';
            right();
            state = 1;
        }
        else if (state == 0 && A[head] == 'Y')
        {
            right();
            break;
        }

        else if (state == 1 && (A[head] == 'b' || A[head] == 'Y'))
        {
            right();
        }
        else if (state == 1 && A[head] == 'a')
        {
            A[head] = 'Y';
            state = 2;
            left();
        }
        else if (state == 2 && A[head] == 'Y' || A[head] == 'b')
        {
            left();
        }
        else if (state == 2 && A[head] == 'X')
        {
            state = 0;
            right();
        }
        else
        {
            cout << "String rejected" << endl;
            return 0;
        }
    }
    for (int i = head; i < A.length(); i++)
    {
        if (A[i] != 'Y')
        {
            cout << "String rejected" << endl;
            return 0;
        }
    }
    cout << "String accepted" << endl;
    return 0;
}
