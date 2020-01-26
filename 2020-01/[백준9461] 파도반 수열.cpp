#include <iostream>
using namespace std;

long long dp[110];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = dp[2] = dp[3] = 1;

	for (int i = 4; i <= 100; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}