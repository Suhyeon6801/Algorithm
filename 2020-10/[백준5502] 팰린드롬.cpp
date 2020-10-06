#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 5010;
char str[MAX];
int dp[MAX][MAX];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cin >> str;

	for (int i = 0; i < N-1; i++)
	{
		if (str[i] != str[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int i = N - 3; i >= 0; i--)
	{
		for (int j = i + 2; j < N; j++)
		{
			if (str[i] == str[j])
				dp[i][j] = dp[i+1][j - 1];
			else
				dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
		}
	}

	cout << dp[0][N - 1] << "\n";
	
	return 0;
}