#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e7 + 7;
vector<bool> used;
vector<vector<pair<int, int>>> g;
int *S; //размер поддерева
ll ans = 0;
int N;
int *to; // вес пути в вершину от родителя

void dfs(int v)
{
	used[v] = true;
	if (g[v].size() == 1)
	{
		S[v] = 1;
	}
	for (vector<pair<int, int>>::iterator i = g[v].begin(); i != g[v].end(); ++i)
	{
		if (!used[(*i).first])
		{
			to[(*i).first] = (*i).second;
			dfs((*i).first);
			S[v] += S[(*i).first];
		}
	}
	ll temp = (ll)S[v] * ((ll)N - (ll)S[v]);
	temp %= mod;
	temp *= ((ll)to[v]);
	temp %= mod;
	//ans += ( S[v] * (N - S[v]) * to[v]);
	ans += temp;
	ans %= mod;
}

int main()
{
	cin >> N;
	used = vector<bool>(N, false);
	S = new int[N];
	to = new int[N];
	for (int i = 0; i < N; i++)
	{
		S[i] = 1;
	}
	g = vector<vector<pair<int, int>>>(N);
	for (int i = 0; i < N - 1; i++)
	{
		int q1, q2, w;
		cin >> q1 >> q2 >> w;
		q1--;
		q2--;
		g[q1].push_back(make_pair(q2, w));
		g[q2].push_back(make_pair(q1, w));
	}
	dfs(0);
	ans *= 2;
	ans %= mod;
	cout << ans;
	return 0;
}