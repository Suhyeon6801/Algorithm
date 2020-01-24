#include <iostream>
#include <algorithm>
using namespace std;
int dp[1010][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int k = 2; k <= n; k++)
	{
		for (int i = 0; i <= 9; i++)
		{
			for (int j = i; j <= 9; j++)
			{
				dp[k][i] += dp[k-1][j];
				dp[k][i] %= 10007;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum += dp[n][i];

	cout << sum%10007;

	return 0;
}