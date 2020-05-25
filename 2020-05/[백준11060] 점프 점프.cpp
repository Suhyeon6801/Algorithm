#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];//i번까지 갔을 때 최소 점프 횟수.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, now;
	cin >> N;

	dp[1] = 1;
	for (int i = 1; i <= N; i++)
	{
		cin >> now;

		if (dp[i] == 0)	continue;

		for (int j = 1; j <= now && (i+j)<=1000; j++)
		{
			if (dp[i+j]>dp[i]+1 || dp[i+j] == 0)
				dp[i+j] = dp[i] + 1;
		}
	}

	for (int i = 1; i <= N; i++)
		cout << dp[i] << " ";
	cout << "\n";

	if (dp[N] != 0)
		cout << dp[N] - 1 << "\n";
	else
		cout << "-1\n";
	
	return 0;
}