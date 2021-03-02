#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		v1--;
		v2--;
		g[v1].push_back(make_pair(v2, w));
		g[v2].push_back(make_pair(v1, w));
	}
	int start_v, end_v;
	cin >> start_v >> end_v;
	start_v--;
	end_v--;
	vector<long long> d(n, 1e18);
	d[start_v] = 0;
	set<pair<int, int>> q; //
	q.insert(make_pair(d[start_v], start_v));

	while (!q.empty())
	{
		int v = q.begin()->second;
		q.erase(q.begin());

		for (size_t j = 0; j < g[v].size(); j++)
		{
			int to = g[v][j].first;
			int len = g[v][j].second;
			;
			if (d[v] + len < d[to])
			{
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}
	cout << d[end_v];
	return 0;
}