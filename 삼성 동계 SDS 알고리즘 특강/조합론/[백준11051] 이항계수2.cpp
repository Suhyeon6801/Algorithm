#include <iostream>
using namespace std;

const int MAX = 1010;
long long int dp[MAX][MAX] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i < MAX; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		dp[i][1] = i;
	}

	for (int i = 3; i < MAX; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%10007;
		}
	}

	cout << dp[n][k] << "\n";


	return 0;
}