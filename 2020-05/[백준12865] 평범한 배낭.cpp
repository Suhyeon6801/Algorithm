#include <iostream>
#include <algorithm>
using namespace std;

struct Bag {
	int W, V;
};

Bag bag[110];
int dp[110][100010];//i번 물건까지 넣어서 k용량의 가방의 가치의의 최댓밗.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> bag[i].W >> bag[i].V;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			if (i == 0)
			{
				if (bag[i].W <= j)
					dp[i][j] = bag[i].V;
				else
					dp[i][j] = 0;
			}
			else
			{
				if (bag[i].W <= j)
					dp[i][j] = max(dp[i - 1][j], bag[i].V + dp[i - 1][j - bag[i].W]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][K] << "\n";

	return 0;
}