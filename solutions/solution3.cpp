#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll *A;
ll mod = 1e9 + 7;
void quickSort(ll *a, int fst, int lst)
{
	if (fst >= lst)
		return;
	int i = fst;
	int j = lst;
	ll pivot = a[(fst + lst) / 2];
	while (i <= j)
	{
		while (abs(a[i]) < abs(pivot))
			i++;
		while (abs(a[j]) > abs(pivot))
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	quickSort(a, fst, j);
	quickSort(a, i, lst);
}
bool AllNeg(ll *a)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= 0)
		{
			return false;
		}
	}
	return true;
}
ll multiplication(ll *a)
{
	ll ans = 1;
	for (int i = 0; i < k; i++)
	{
		ans *= a[n - 1 - i];
		ans %= mod;
	}
	if (ans < 0)
	{
		ans += mod;
	}
	return ans;
}
int main()
{
	cin >> n >> k;
	A = new ll[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	quickSort(A, 0, n - 1);
	////////////////////////////////////
	int minus_count = 0;
	for (int i = 0; i < k; i++)
	{
		if (A[n - 1 - i] < 0)
		{
			minus_count++;
		}
	}
	if (minus_count % 2 == 0)
	{
		cout << multiplication(A);
		return 0;
	}
	else
	{
		if (AllNeg(A))
		{
			ll ans = 1;
			for (int i = 0; i < k; i++)
			{
				ans *= A[i];
				ans %= mod;
			}
			if (ans < 0)
			{
				ans += mod;
			}
			cout << ans;
			return 0;
		}
		//ищем 2 версии ответа
		ll max_pos = -1;
		ll min_neg = -1;
		for (int i = 0; i < n - k; i++)
		{
			if (A[n - k - 1 - i] > 0)
			{
				max_pos = n - k - 1 - i;
				break;
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (A[n - k + i] < 0)
			{
				min_neg = n - k + i;
				break;
			}
		}
		ll min_pos = -1;
		ll max_neg = -1;
		for (int i = 0; i < n - k; i++)
		{
			if (A[n - k - 1 - i] < 0)
			{
				max_neg = n - k - 1 - i;
				break;
			}
		}
		for (int i = 0; i < k; i++)
		{
			if (A[n - k + i] > 0)
			{
				min_pos = n - k + i;
				break;
			}
		}
		if (max_neg != -1 and max_pos != -1 and min_neg != -1 and min_pos != -1) //если все элементы нашлись
		{
			if (abs((float)max_neg / (float)min_pos) >= abs((float)max_pos / (float)min_neg) and max_pos != -1)
			{
				swap(A[max_neg], A[min_pos]);
			}
			else
			{
				swap(A[max_pos], A[min_neg]);
			}
		}
		else if (max_neg != -1 and min_pos != -1)
		{
			swap(A[max_neg], A[min_pos]);
		}
		else if (max_pos != -1 and min_neg != -1)
		{
			swap(A[max_pos], A[min_neg]);
		}
		cout << multiplication(A);
	}
	return 0;
}