#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1010][3];
int arr[1010][3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	dp[1][2] = arr[1][2];
	dp[1][3] = arr[1][3];

	for (int i = 2; i <= N; i++)
	{
		dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
		dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]) + arr[i][3];
	}
	
	long long getMin = 987654321;
	for (int i = 1; i <= 3; i++)
	{
		if (getMin > dp[N][i])
			getMin = dp[N][i];
	}
	cout << getMin;

	return 0;
}