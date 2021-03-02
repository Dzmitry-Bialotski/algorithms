#include <iostream>
using namespace std;
int main()
{
	int input;
	cin >> input;
	if (input % 400 == 0 || (input % 4 == 0 && input % 100 != 0))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}