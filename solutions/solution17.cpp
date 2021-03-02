#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool find(ll x, ll *A, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (A[i] == x)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int N;
	cin >> N;
	ll *A = new ll[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	if (find((ll)1021, A, N) and find((ll)1031, A, N) and find((ll)1033, A, N))
		cout << "YES";
	else if (find((ll)1021 * 1031, A, N) and find((ll)1033, A, N))
		cout << "YES";
	else if (find((ll)1021 * 1033, A, N) and find((ll)1031, A, N))
		cout << "YES";
	else if (find((ll)1031 * 1033, A, N) and find((ll)1021, A, N))
		cout << "YES";
	else if (find((ll)1087388483, A, N))
		cout << "Yes";
	else
		cout << "NO";
}