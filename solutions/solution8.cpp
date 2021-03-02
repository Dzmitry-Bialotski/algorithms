#include <bits/stdc++.h>
using namespace std;
bool isSimpleString(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[0])
			return false;
	}
	return true;
}
bool isPalindrome(string s)
{
	int i = 0;
	int j = s.size() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	if (isSimpleString(s))
	{
		cout << "-1";
	}
	else if (isPalindrome(s))
	{
		cout << n - 1;
	}
	else
		cout << n;
	return 0;
}