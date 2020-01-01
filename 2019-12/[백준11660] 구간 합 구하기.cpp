#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1034;
int map[MAX][MAX] = { 0 };
int dp[MAX][MAX]{ 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int x1, y1, x2, y2;
	long long int sum, result;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += map[i][j];
			dp[i][j] = sum;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		result = 0;
		for (int i = x1; i <= x2; i++)
		{
			result += dp[i][y2] - dp[i][y1-1];
		}
		cout << result << "\n";
	}

	

	return 0;
}