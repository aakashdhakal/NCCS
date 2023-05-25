#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int c, f;
    float n;

    cout << "Enter a number: ";
    cin >> n;

    c = ceil(n);
    f = floor(n);

    cout << "Ceiling of " << n << " is " << c << " and floor is " << f << endl;
    return 0;
}
