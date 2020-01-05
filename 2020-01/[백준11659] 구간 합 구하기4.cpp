#include <iostream>

using namespace std;

const int MAX = 100010;
int dp[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
	}

	//dp[1] = arr[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] += dp[i - 1];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << dp[b]-dp[a-1] << "\n";
	}

	return 0;
}