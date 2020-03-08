#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1034;
long long dp[MAX][MAX] = { 0, };
long long map[MAX][MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long sum, temp;
	int x1, y1, x2, y2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dp[i][j];
		}
	}
	
	//dp
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] += dp[i][j - 1];
		}
	}

	for (int k = 0; k < m; k++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		sum = 0;
		for (int i = x1; i <= x2; i++)
		{
			sum += dp[i][y2] - dp[i][y1 - 1];
		}
		cout << sum << "\n";
	}

	
	return 0;
}