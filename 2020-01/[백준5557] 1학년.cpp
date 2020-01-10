#include <iostream>
using namespace std;

const int MAX = 110;
long long int dp[MAX][MAX];
int arr[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0][arr[0]] = 1;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j] > 0)
			{
				if (arr[i] + j <= 20)
				{
					dp[i][arr[i] + j] += dp[i - 1][j];
				}

				if (j - arr[i] >= 0)
				{
					dp[i][j - arr[i]] += dp[i - 1][j];
				}
			}
		}
	}

	cout << dp[n - 2][arr[n - 1]] << "\n";
	return 0;
}