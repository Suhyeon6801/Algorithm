#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100010];
long long dp[100010];//i번째까지 최대값
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	long long getMax = dp[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		getMax = max(dp[i], getMax);
	}

	cout << getMax;

	return 0;
}