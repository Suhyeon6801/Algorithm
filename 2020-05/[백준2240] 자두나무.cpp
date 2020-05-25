//어렵다..ㅠㅠ 다시!!

#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][1010][40];//자두나무위치, 떨어진 시간,최대 움직인 횟수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, W, num;
	cin >> T >> W;

	for(int i=1; i<=T; i++)
	{
		cin >> num;

		for (int j = 1; j <= W + 1; j++)//최대 횟수가 2면 0(아예 이동안함!),1,2가 포함됨.
		{
			if (num == 1)
			{
				dp[1][i][j] = max(dp[1][i - 1][j] + 1, dp[2][i - 1][j - 1]+1);
				dp[2][i][j] = max(dp[1][i - 1][j-1], dp[2][i - 1][j]);
			}
			else
			{
				if (i == 1 && j == 1)	continue;

				dp[1][i][j] = max(dp[2][i - 1][j - 1], dp[1][i - 1][j]);
				dp[2][i][j] = max(dp[1][i - 1][j - 1] + 1, dp[2][i - 1][j] + 1);
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= W + 1; i++)
		ans = max(dp[1][T][i], dp[2][T][i]);
	
	cout << ans << "\n";
	
	return 0;
}