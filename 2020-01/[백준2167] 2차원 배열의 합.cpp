#include <iostream>
#include <algorithm>
using namespace std;

int dp[310][310];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <=m; j++)
		{
			dp[i][j] += dp[i][j-1];
		}
	}

	cin >> k;
	for (int tc = 0; tc < k; tc++)
	{
		int i, j, x, y;
		int sum = 0;
		cin >> i >> j >> x >> y;

		for (int a = i; a <= x; a++)
		{
			sum += dp[a][y] - dp[a][j - 1];
		}
		cout << sum << "\n";
	}
	


	return 0;
}