#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<int> *add;
multiset<int> *del;
multiset<int> temp;
int main()
{
	temp.insert(0);
	int n, m;
	cin >> n >> m;
	add = new multiset<int>[n];
	del = new multiset<int>[n];
	for (int i = 0; i < m; i++)
	{
		int l, r, v;
		cin >> l >> r >> v;
		l--;
		r--;
		add[l].insert(v);
		if (r + 1 < n)
			del[r + 1].insert(v);
	}
	for (int i = 0; i < n; i++)
	{
		for (multiset<int>::iterator j = add[i].begin(); j != add[i].end(); j++)
		{
			temp.insert(*j);
		}
		for (multiset<int>::iterator j = del[i].begin(); j != del[i].end(); j++)
		{
			temp.erase(temp.find(*j));
		}
		cout << *temp.rbegin() << " ";
	}
	return 0;
}