#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	int q;
	int isChanged[len];
	bool invert = false;
	for (int i = 0; i < len; i++)
	{
		isChanged[i] = 0;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int left, right;
		cin >> left >> right;
		left--;
		right--;
		if (left > right)
			swap(left, right);
		isChanged[left]++;
		if (right + 1 < len)
			isChanged[right + 1]++;
	}
	for (int i = 0; i < len; i++)
	{
		if (isChanged[i] % 2 == 1)
		{
			invert = !invert;
		}
		if (invert)
		{
			if (islower(s[i]))
			{
				cout << (char)toupper(s[i]);
			}
			else
			{
				cout << (char)tolower(s[i]);
			}
		}
		else
		{
			cout << (char)s[i];
		}
	}
	return 0;
}