#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll X;
	cin >> X;
	if (X % 10 == 0)
	{
		cout << "NO";
	}
	else
	{
		cout << X % 10;
	}
	return 0;
}