#include <iostream>
using namespace std;

int dp[310];//i명일때 방을 채울수 있는지

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C, N;
	cin >> A >> B >> C >> N;

	dp[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (i >= A)
		{
			if (i >= B)
			{
				if (i >= C)	dp[i] = dp[i - A] + dp[i - B] + dp[i - C];
				else	dp[i] = dp[i - A] + dp[i - B];
			}
			else	dp[i] = dp[i - A];
		}
		else	dp[i] = 0;
	}

	if (dp[N] == 0)
		cout << "0\n";
	else
		cout << "1\n";

	return 0;
}