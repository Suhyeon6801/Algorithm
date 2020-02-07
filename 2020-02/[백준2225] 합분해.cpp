#include <iostream>
using namespace std;

const int MOD = 1000000000;
long long dp[210][210];//K번 더해서 N이 되는 방법 개수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}

			dp[i][j] %= MOD;
		}
	}

	cout << dp[K][N] << "\n";

	return 0;
}