#include <iostream>
using namespace std;

const int MOD = 1000000000;
long long dp[110][11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int k = 2; k <= n; k++)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (i == 0)
			{
				dp[k][i] = dp[k - 1][i + 1];
			}
			else if (i == 9)
			{
				dp[k][i] = dp[k - 1][i - 1];
			}
			else 
			{
				dp[k][i] = (dp[k - 1][i - 1] + dp[k - 1][i + 1]) % MOD;
			}	
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += dp[n][i];

	cout << sum % MOD;

	return 0;
}