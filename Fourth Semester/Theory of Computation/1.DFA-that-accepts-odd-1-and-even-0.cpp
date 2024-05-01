#include <iostream>
using namespace std;

string str;
int state = 0;

int main()
{
    cout << "Enter the string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0' && str[i] != '1')
        {
            cout << "String not accepted.\nPlease enter a string over {0,1}" << endl;
            return 0;
        }

        if (state == 0 && str[i] == '0')
            state = 1;
        else if (state == 0 && str[i] == '1')
            state = 2;
        else if (state == 1 && str[i] == '0')
            state = 0;
        else if (state == 1 && str[i] == '1')
            state = 3;
        else if (state == 2 && str[i] == '0')
            state = 3;
        else if (state == 2 && str[i] == '1')
            state = 0;
        else if (state == 3 && str[i] == '0')
            state = 2;
        else if (state == 3 && str[i] == '1')
            state = 1;
    }

    if (state == 2)
        cout << "String accepted" << endl;
    else
        cout << "String not accepted" << endl;

    return 0;
}
