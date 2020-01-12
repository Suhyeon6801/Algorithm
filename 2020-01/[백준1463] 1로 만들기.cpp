#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000010;
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int n;
	cin >> n;
	for (int i = 4; i <= n; i++)
	{
		//1빼기
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)//2나누기
		{
			dp[i] = min(dp[i / 2]+1, dp[i]);
		}
		if (i % 3 == 0)//3나누기
		{
			dp[i] = min(dp[i / 3]+1, dp[i]);
		}
	}

	cout << dp[n] << "\n";

	return 0;
}