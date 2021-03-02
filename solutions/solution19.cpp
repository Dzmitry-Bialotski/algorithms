#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int N;
vector<pair<int, int>> inverses;

vector<pair<int, int>> inverses_merge(vector<pair<int, int>> ls1, vector<pair<int, int>> ls2)
{
	vector<pair<int, int>> result;
	int i = 0, j = 0;
	while (i < ls1.size() and j < ls2.size())
	{
		if (ls1[i].first < ls2[j].first)
		{
			result.push_back(ls1[i]);
			i++;
		}
		else
		{
			result.push_back(make_pair(ls2[j].first, ls2[j].second + ls1.size() - i));
			j++;
		}
	}
	while (i < ls1.size())
	{
		result.push_back(ls1[i]);
		i++;
	}
	while (j < ls2.size())
	{
		result.push_back(ls2[j]);
		j++;
	}
	return result;
}

vector<pair<int, int>> inverses_get(vector<pair<int, int>> l)
{
	if (l.size() == 1)
	{
		// l[0].second = 0;
		return l;
	}
	else
	{
		vector<pair<int, int>> l1;
		for (int i = 0; i < l.size() / 2; i++)
		{
			l1.push_back(l[i]);
		}
		l.erase(l.begin(), l.begin() + l.size() / 2);
		return inverses_merge(inverses_get(l1), inverses_get(l));
	}
}
int main()
{
	cin >> N;
	ll result = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		inverses.push_back(make_pair(temp, 0));
	}
	inverses = inverses_get(inverses);
	for (int i = 0; i < inverses.size(); i++)
	{
		result += inverses[i].second;
	}
	cout << result;
	return 0;
}