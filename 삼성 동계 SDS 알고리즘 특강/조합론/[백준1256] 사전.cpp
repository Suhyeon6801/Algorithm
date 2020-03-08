#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 210;
int dp[MAX][MAX];

void Pascal()
{
	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = min(dp[i - 1][j - 1] + dp[i - 1][j], (int)1e9);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Pascal();

	int n, m, k;
	string s = "";
	cin >> n >> m >> k;

	int total = n + m;
	if (k > dp[total][m])
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 0; i < total; i++)
		{
			if (k > dp[n + m - 1][m])
			{
				s += "z";
				k -= dp[n + m - 1][m];
				m--;
			}
			else
			{
				s += "a";
				n--;
			}
		}
		cout << s << "\n";
	}

	return 0;
}