#include <iostream>
#include <algorithm>
using namespace std;

long long dp[10010];//i번째까지 마셨을 때 최댓값
int arr[10010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i-2], dp[i-3]+arr[i-1]) + arr[i];
		dp[i] = max(dp[i - 1], dp[i]);
	}

	cout << max(dp[n - 1], dp[n]);

	return 0;
}