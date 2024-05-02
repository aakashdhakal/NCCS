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
    A += "B"; // Add a blank symbol to the end of the string
    do
    {
        if (state == 0 && A[head] == 'a')
        {
            A[head] = 'X';
            right();
            state = 1;
        }
        else if (state == 1 && A[head] == 'a')
        {
            right();
            state = 1;
        }

        else if (state == 1 && A[head] == 'c')
        {
            right();
            state = 2;
        }
        else if (state == 2 && A[head] == 'b')
        {
            A[head] = 'Y';
            left();
            state = 3;
        }
        else if (state == 2 && A[head] == 'Y')
        {
            right();
            state = 2;
        }

        else if (state == 3 && (A[head] == 'Y' || A[head] == 'c' || A[head] == 'a'))
        {
            left();
            state = 3;
        }
        else if (state == 3 && A[head] == 'X')
        {
            right();
            state = 0;
        }
        else if (state == 0 && A[head] == 'c')
        {
            right();
            state = 4;
        }
        else if (state == 4 && A[head] == 'Y')
        {
            right();
            state = 4;
        }
        else if (state == 4 && A[head] == 'B')
        {
            state = 5;
            break;
        }
        else
        {
            cout << "String rejected " << endl;
            return 0;
        }
    } while (true);
    if (state == 5)
    {
        cout << "String Accepted" << endl;
    }
    return 0;
}
