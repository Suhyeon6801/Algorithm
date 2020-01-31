#include <iostream>
#include <cstring>
using namespace std;

long long dp[110][110];
int arr[110][110];
int n;

long long dfs(int y, int x)
{
	if (y == n && x == n)	return 1;

	long long &ret = dp[y][x];
	if (ret != -1)	
		return ret;

	ret = 0;
	if (x != n && arr[y][x] + x <= n)
		ret += dfs(y, arr[y][x] + x);
	if (y != n && arr[y][x] + y <= n)
		ret += dfs(y + arr[y][x], x);

	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(1, 1) << "\n";

	return 0;
}