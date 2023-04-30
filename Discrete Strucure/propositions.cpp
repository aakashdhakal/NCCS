#include <iostream>
using namespace std;

int main()
{
	int op;
	bool a[] = {0, 0, 1, 1}, b[] = {0, 1, 0, 1};

	char w;

	cout << "Enter 1 for conjunction" << endl
		 << "Enter 2 for implication" << endl
		 << "Enter 3 for bi-implication" << endl
		 << "Enter 4 for disjunction" << endl
		 << "Enter 5 to exit" << endl;
	cout << "--------------------------------------------" << endl;
	cin >> op;
	switch (op)
	{
	case 1:
		cout << "\t Conjunction" << endl;
		cout << "\tA \tB \tA^B" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (i == j)
				{
					cout << "\t" << a[i] << "\t" << b[j] << "\t" << a[i] * b[j] << endl;
				}
		}
		break;

	case 2:
		cout << "\t Implication" << endl;
		cout << "\tA \tB \tA->B" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (i == j)
				{
					cout << "\t" << a[i] << "\t" << b[j] << "\t" << (!a[i] || b[j]) << endl;
				}
		}
		break;
	case 3:
		cout << "\t Bi-Implication" << endl;
		cout << "\tA \tB \tA<->B" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (i == j)
				{
					cout << "\t" << a[i] << "\t" << b[j] << "\t" << (!a[i] + b[j]) * (!b[j] + a[i]) << endl;
				}
		}
		break;
	case 4:
		cout << "\t Disjunction" << endl;
		cout << "\tA \tB \tAvB" << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (i == j)
				{
					cout << "\t" << a[i] << "\t" << b[j] << "\t" << (a[i] || b[j]) << endl;
				}
		}
		break;
	case 5:
		return 0;
		break;
	default:
		cout << "Invalid Input" << endl;
		break;
	}
	cout << "Do you wish to continue? (Y/N)" << endl;
	cin >> w;
	if (w == 'Y' || w == 'y')
	{
		main();
	}
	else
	{
		return 0;
	}
	return 0;
}