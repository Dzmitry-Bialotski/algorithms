#include <bits/stdc++.h>
using namespace std;
int N, M, I, J;
int **A;
bool found = 0;
bool changed = true;
queue<int> qX;
queue<int> qY;
void pushFriends(int x, int y)
{
	changed = false;
	if (x == I and y == J)
	{
		found = true;
		return;
	}

	if (x + 2 < N and y + 1 < M)
	{
		if (A[x + 2][y + 1] == 0)
		{
			qX.push(x + 2);
			qY.push(y + 1);
			A[x + 2][y + 1] = A[x][y] + 1;
			changed = true;
		}
	}
	if (x + 2 < N and y - 1 >= 0)
	{
		if (A[x + 2][y - 1] == 0)
		{
			qX.push(x + 2);
			qY.push(y - 1);
			A[x + 2][y - 1] = A[x][y] + 1;
			changed = true;
		}
	}
	if (x + 1 < N and y + 2 < M)
	{
		if (A[x + 1][y + 2] == 0)
		{
			qX.push(x + 1);
			qY.push(y + 2);
			A[x + 1][y + 2] = A[x][y] + 1;
			changed = true;
		}
	}
	if (x + 1 < N and y - 2 >= 0)
	{
		if (A[x + 1][y - 2] == 0)
		{
			qX.push(x + 1);
			qY.push(y - 2);
			A[x + 1][y - 2] = A[x][y] + 1;
			changed = true;
		}
	} //
	if (x - 2 >= 0 and y + 1 < M)
	{
		if (A[x - 2][y + 1] == 0)
		{
			qX.push(x - 2);
			qY.push(y + 1);
			A[x - 2][y + 1] = A[x][y] + 1;
			changed = true;
		}
	}
	if (x - 2 >= 0 and y - 1 >= 0)
	{
		if (A[x - 2][y - 1] == 0)
		{
			qX.push(x - 2);
			qY.push(y - 1);
			A[x - 2][y - 1] = A[x][y] + 1;
			changed = true;
		}
	}
	if (x - 1 >= 0 and y + 2 < M)
	{
		if (A[x - 1][y + 2] == 0)
		{
			qX.push(x - 1);
			qY.push(y + 2);
			A[x - 1][y + 2] = A[x][y] + 1;
			changed = true;
		}
	}
	if (x - 1 >= 0 and y - 2 >= 0)
	{
		if (A[x - 1][y - 2] == 0)
		{
			qX.push(x - 1);
			qY.push(y - 2);
			A[x - 1][y - 2] = A[x][y] + 1;
			changed = true;
		}
	}
}
int main()
{

	cin >> N >> M >> I >> J;
	I--;
	J--;
	A = new int *[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}
	qX.push(0);
	qY.push(0);
	while (!found and !qX.empty())
	{
		pushFriends(qX.front(), qY.front());
		qX.pop();
		qY.pop();
	}
	if (found)
		cout << A[I][J];
	else
		cout << "NEVAR";
	return 0;
}