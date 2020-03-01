#include <iostream>
using namespace std;

const int MAX = 10010;
int dp[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	int sum = 0;
	int getMin = MAX;
	cin >> M >> N;

	for (int i = 1; i <= N; i++)
		dp[i] = i * i;

	for (int i = 1; i <= N; i++)
	{
		if (dp[i] >= M && dp[i] <= N)
		{
			sum += dp[i];

			if (getMin > dp[i])
				getMin = dp[i];
		}
	}

	if (getMin == MAX)
		cout << "-1\n";
	else
	{
		cout << sum << "\n";
		cout << getMin << "\n";
	}

	return 0;
}