#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	char c;
	int len = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			dp[i][j] = c - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (dp[i][j] == 1)
			{
				dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
			}
			len = max(len, dp[i][j]);
		}
	}
	cout << len*len << "\n";

	return 0;
}