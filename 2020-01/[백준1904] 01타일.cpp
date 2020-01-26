#include <iostream>
using namespace std;

int dp[1000010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000000; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}

	int N;
	cin >> N;
	
	cout << dp[N] % 15746;

	return 0;
}