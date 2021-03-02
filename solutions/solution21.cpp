#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int max(int a, int b)
{
	return (a > b) ? a : b;
}
vector<bool> used;
vector<vector<int>> g;
int *a, *b, *c;
void dfs(int v)
{
	used[v] = true;
	if (g[v].size() == 1) //если это лист
	{
		a[v] = 0;
		b[v] = 0;
	}
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i)
	{
		if (!used[*i])
		{
			dfs(*i);

			a[v] = max(a[v], b[*i] + 1 - c[*i]);
			b[v] += c[*i];
		}
	}
	a[v] += b[v];
	c[v] = max(a[v], b[v]);
}

int main()
{
	int N;
	cin >> N; //N - вершины, M - ребраё
	a = new int[N];
	b = new int[N];
	c = new int[N];
	used = vector<bool>(N, false);
	g = vector<vector<int>>(N);
	int G[N - 1][2];
	for (int i = 0; i < N - 1; i++)
	{
		int q1, q2;
		cin >> q1 >> q2;
		q1--;
		q2--;
		g[q1].push_back(q2);
		g[q2].push_back(q1);
	}
	dfs(0);
	cout << c[0];
	return 0;
}