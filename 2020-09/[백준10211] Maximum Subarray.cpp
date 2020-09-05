#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1010];//i번째 까지 더했을 때 최댓값
int arr[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		int N, result = -987654321;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		dp[0] = arr[0];

		for (int i = 1; i < N; i++)
		{
			dp[i] = max(dp[i - 1] + arr[i], arr[i]);
			result = max(result, dp[i]);
		}

		cout << result << "\n";
	}

	return 0;
}