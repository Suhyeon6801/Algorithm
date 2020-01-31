#include <iostream>
using namespace std;

int dp[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	int n;
	cin >> n;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	cout << dp[n] % 10007;

	return 0;
}