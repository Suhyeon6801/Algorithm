#include <iostream>
using namespace std;
const int MAX = 40;
long long int dp[MAX][MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0][0] = 1;
	for (int i = 1; i <= 30; i++)
	{
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= 30; i++)
	{
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	int tc, n, m;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n >> m;

		cout << dp[m][n] << "\n";
	}


	return 0;
}