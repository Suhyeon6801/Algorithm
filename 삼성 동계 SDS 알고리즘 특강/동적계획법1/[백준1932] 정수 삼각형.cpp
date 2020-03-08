#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 510;
int dp[MAX][MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long int getMax = -1;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 2; i <= n; i++)
	{
		dp[i][1] += dp[i - 1][1];
		dp[i][i] += dp[i - 1][i - 1];
	}

	for (int i = 3; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (getMax < dp[i][j])	getMax = dp[i][j];
		}
	}

	cout << getMax << "\n";

	return 0;
}