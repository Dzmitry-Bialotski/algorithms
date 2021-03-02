#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int n = 0;
	int temp = a;
	while (temp > 0)
	{
		n++;
		temp /= 10;
	}
	int *A = new int[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = a % 10;
		a /= 10;
	}
	if (n == 1)
	{
		cout << -1;
		return 0;
	}
	int ans;
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			//начало алгоритма
			for (int j = 0; j < i + 1; j++)
			{
				if (A[j] > A[i + 1])
				{
					int temp = A[j];
					A[j] = A[i + 1];
					A[i + 1] = temp;
					break;
				}
			}
			int j = 0;
			while (j < i - j)
			{
				int temp = A[j];
				A[j] = A[i - j];
				A[i - j] = temp;
				j++;
			}
			ans = 0;
			for (int j = 0; j < n; j++)
			{
				ans += A[j] * pow(10, j);
			}
			break;
		}
		else
			ans = -1;
	}

	cout << ans;

	return 0;
}