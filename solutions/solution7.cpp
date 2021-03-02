#include <bits/stdc++.h>
int main()
{
	int n, m, x1, y1, x2, y2;
	std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	std::cout << ((abs(y2 - y1) == abs(x2 - x1)) ? "NO" : "YES");
	return 0;
}