#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Max(ll *A, int size)
{
	ll max = abs(A[0]);
	for (int i = 1; i < size; i++)
	{
		if (abs(A[i]) > max)
		{
			max = abs(A[i]);
		}
	}
	for (int i = 1; i < size; i++)
	{
		if (abs(A[i]) == max)
		{
			A[i] = 0;
			break;
		}
	}
	return max;
}
int main()
{
	int n;
	cin >> n;
	ll *A = new ll[n];
	ll *pos = new ll[n];
	ll *neg = new ll[n];
	int pos_count = 0;
	int neg_count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	ll max = A[0] * A[1];

	for (int i = 0; i < n; i++)
	{
		if (A[i] >= 0)
		{
			pos[pos_count] = A[i];
			pos_count++;
		}
		else
		{
			neg[neg_count] = A[i];
			neg_count++;
		}
	}
	ll max_pos_first = 0, max_pos_second = 0, max_neg_first = 0, max_neg_second = 0;
	ll max1 = -2e18;
	ll max2 = -2e18;
	if (pos_count >= 2)
	{
		max_pos_first = Max(pos, pos_count);
		max_pos_second = Max(pos, pos_count);
		max1 = max_pos_first * max_pos_second;
	}
	if (neg_count >= 2)
	{
		max_neg_first = Max(neg, neg_count);
		max_neg_second = Max(neg, neg_count);
		max2 = max_neg_first * max_neg_second;
	}
	ll RealMax = max1 > max2 ? max1 : max2;
	RealMax = RealMax > max ? RealMax : max;
	cout << RealMax;
}