#include <iostream>
#include <algorithm>
using namespace std;

int dp[30];//i번째까지 일한 날 최대 금액, 돈은 i+t[i]날 돈을 받자!
int T[30];
int P[30];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//int getMax = -1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> T[i] >> P[i];

	//1.i번째날 일한 경우, 2. i번째날 일하지 않은경우
	//돈은 i+1날에 받는다.
	for (int i = 1; i <= n+1; i++)
	{
		for (int j = 1; j < i; j++)
		{
			//j번째 날 일 안하고, i번째날까지 온경우
			dp[i] = max(dp[i], dp[j]);

			if (j + T[j] == i)
				dp[i] = max(dp[i], dp[j] + P[j]);
		}
	}

	//cout << getMax;
	cout << dp[n + 1] << "\n";

	return 0;
}