#include <iostream>
#include <algorithm>
using namespace std;

int memory[110];
int cost[110];
int dp[110][10010];//1~i벌째 앱까지 비 활성화 시 확보 가능한 최대 메모리값,
int result = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int maxCost = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> memory[i];

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		maxCost += cost[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= maxCost; j++)
		{
			if (j < cost[i])	dp[i][j] = dp[i - 1][j];//i번째 비용이 더 크다면 i번째앱은 선택 안함.
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);//선택X->이전꺼 그대로, 선택하면 이전꺼 비용은 빼주고 메모리 더해줌.
			}

			if (dp[i][j] >= m && j < result)//m바이트 이상 확보시, 그 때 비용의 최솟값을 구한다.
				result = j;
		}
	}

	cout << result << "\n";

	return 0;
}