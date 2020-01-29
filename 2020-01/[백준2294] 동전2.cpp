#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int dp[10010];
int arr[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= k; i++)
		dp[i] = INF;

	//dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = arr[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - arr[i]]+1);
	}

	if (dp[k] == INF)	cout << "-1\n";
	else
		cout << dp[k] << "\n";

	return 0;
}