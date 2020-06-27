#include <iostream>
using namespace std;

const int MOD = 1000000;
long long n;
long long dp[1500010];//피사노주기!! -> [백준9471] 피사노주기 참조

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 0; i < 1500000; i++)
		dp[i + 2] = (dp[i + 1] + dp[i])%MOD;

	cin >> n;

	cout << dp[n % 1500000];

	return 0;
}