#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, start, End, length;
ll **g;
ll **matrix_mult(ll **a, ll **b);
ll **bin_pow(ll **a, int k)
{
	if (k == 0)
	{
		ll **c = new ll *[n];
		for (int i = 0; i < n; i++)
		{
			c[i] = new ll[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				c[i][j] == 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			c[i][i] = 1;
		}
		return c;
	}
	if (k % 2 == 1)
	{
		return matrix_mult(bin_pow(a, k - 1), a);
	}
	else
	{
		ll **b = bin_pow(a, k / 2);
		return matrix_mult(b, b);
	}
}
ll **matrix_mult(ll **a, ll **b)
{
	ll **c = new ll *[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new ll[n];
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				ll temp = (ll)a[i][k] * (ll)b[k][j];
				temp %= (ll)(1e9 + 7);
				c[i][j] += temp;
				c[i][j] %= (ll)(1e9 + 7);
			}
		}
	}
	return c;
}

int main()
{
	cin >> n >> m;
	g = new ll *[n];
	for (int i = 0; i < n; i++)
	{
		g[i] = new ll[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g[i][j] = 0;
		}
	}
	cin >> start >> End >> length;
	start--;
	End--;

	for (int i = 0; i < m; i++)
	{
		int q1, q2;
		cin >> q1 >> q2;
		q1--;
		q2--;
		g[q1][q2]++;
		g[q2][q1]++;
	}
	ll **ans = bin_pow(g, length);
	cout << ans[start][End];
	return 0;
}