#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[40];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	for (int i = 4; i <= n; i+=2)
	{		
		dp[i] = dp[i - 2] * 3;
		//길이가 2씩 늘어날때 마다 새로운 경우 2개씩 추가
		for (int j = 4; j<=i; j+=2)
		{
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[n];
	
	return 0;
}