#include <iostream>
using namespace std;

const int MOD = 9901;
int dp[3][100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[0][1] = 1;//한마리도 배치X
	dp[1][1] = 1;//왼쪽에만 배치
	dp[2][1] = 1;//오른쪽에만 배치

	for (int i = 2; i <= n; i++)
	{
		dp[0][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1])%MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1])%MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1])%MOD;
	}

	cout << (dp[0][n] + dp[1][n] + dp[2][n]) % MOD;

	return 0;
}