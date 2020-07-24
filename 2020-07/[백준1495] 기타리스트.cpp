#include <iostream>
#include <algorithm>
using namespace std;

int vol[110];
bool dp[110][1010];//i번째 곡일때, j번째 크기의 볼륨을 연주할 수 있다면 1, 아니면 0

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

	int N, S, M;
	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++)
		cin >> vol[i];

	dp[0][S] = true;

	for (int i = 0; i <= N - 1; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if (!dp[i][j])	continue;
			
			if (j - vol[i + 1] >= 0)
				dp[i + 1][j - vol[i + 1]] = true;
			if (j + vol[i + 1] <= M)
				dp[i + 1][j + vol[i + 1]] = true;
		}
	}

	int result = -1;
	for (int i = 0; i <= M; i++)
	{
		if (dp[N][i])
			result = i;
	}

	cout << result << "\n";

	return 0;
}