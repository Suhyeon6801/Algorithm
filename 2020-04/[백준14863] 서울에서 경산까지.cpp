#include <iostream>
#include <algorithm>
using namespace std;

int dp[110][100010] = { 0, };//i구간을 j분 안에 지났을 때 얻는 최대금액

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	int wm, wc, bm, bc;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> wm >> wc >> bm >> bc;

		if (i == 1)
		{
			dp[i][wm] = wc;
			dp[i][bm] = max(dp[i][bm], bc);
		}
		else
		{
			for (int j = 0; j <= K; j++)
			{
				if (dp[i - 1][j] == 0)	continue;
				else
				{
					if (j + wm <= K)
						dp[i][j + wm] = max(dp[i][j + wm], dp[i - 1][j] + wc);
					if (j + bm <= K)
						dp[i][j + bm] = max(dp[i][j + bm], dp[i - 1][j] + bc);
				}
			}
		}
	}

	int getMax = -1;
	for (int i = 1; i <= K; i++)
		getMax = max(dp[N][i], getMax);

	cout << getMax << "\n";


	return 0;
}