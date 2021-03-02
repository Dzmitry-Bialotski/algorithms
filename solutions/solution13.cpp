#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool *used;
vector<vector<int>> g;

void dfs(int v)
{
	used[v] = true;
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i)
	{
		if (!used[*i])
			dfs(*i);
	}
}

int main()
{
	int count = 0;
	int N, M;
	cin >> N >> M;
	used = new bool[N + 1];
	g = vector<vector<int>>(N + 1);
	int G[M][2];
	for (int i = 0; i < M; i++)
	{
		int q1, q2;
		cin >> q1 >> q2;
		g[q1].push_back(q2);
		g[q2].push_back(q1);
	}

	for (int i = 1; i <= N; i++)
	{
		if (used[i] == 0)
		{
			dfs(i);
			count++;
		}
	}
	if (count == 1)
		cout << M - N + 1;
	else
		cout << -1;
	return 0;
}