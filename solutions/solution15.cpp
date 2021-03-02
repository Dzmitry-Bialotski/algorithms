#include <iostream>
using namespace std;

int main()
{
	int n, max_val;
	long long ans = 0;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	max_val = A[0];
	for (int i = 1; i < n; i++)
	{
		if (A[i] > max_val)
		{
			ans += (A[i] - max_val);
			max_val = A[i];
		}
		else if (A[i] < A[i - 1])
		{
			ans += (A[i - 1] - A[i]);
		}
	}
	cout << ans;
	return 0;
}