#include <iostream>
using namespace std;

int main()
{
    string str;
    int state = 0;

    cout << "Enter the string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
        {
            cout << "String not accepted.\nPlease enter a string over {a,b}" << endl;
            return 0;
        }

        if (state == 0 && str[i] == 'a')
            state = 0;
        else if (state == 0 && str[i] == 'b')
            state = 1;
        else if (state == 1 && str[i] == 'a')
            state = 2;
        else if (state == 1 && str[i] == 'b')
            state = 1;
        else if (state == 2 && str[i] == 'a')
            state = 0;
        else if (state == 2 && str[i] == 'b')
            state = 1;
    }

    if (state == 2)
        cout << "String accepted" << endl;
    else
        cout << "String not accepted" << endl;

    return 0;
}
