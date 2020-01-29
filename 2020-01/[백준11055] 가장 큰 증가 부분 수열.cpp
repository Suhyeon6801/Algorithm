#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];
int arr[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int getMax = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
		getMax = max(dp[i], getMax);
	}
	cout << getMax << "\n";

	return 0;
}