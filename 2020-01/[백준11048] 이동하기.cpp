#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010][1010];
int dp[1010][1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];
		}
	}

	cout << dp[n][m];

	return 0;
}