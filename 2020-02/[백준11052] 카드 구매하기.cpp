#include <iostream>
#include <algorithm>
using namespace std;
int N;
int p[1010];
int dp[1010];//n번 카드팩까지 골랐을 때 최댓값.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> p[i];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[N];


	return 0;
}