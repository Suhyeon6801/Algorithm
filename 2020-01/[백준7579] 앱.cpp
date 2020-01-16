#include <iostream>
#include <algorithm>
using namespace std;

int memory[110];
int cost[110];
int dp[110][10010];//1~i��° �۱��� �� Ȱ��ȭ �� Ȯ�� ������ �ִ� �޸𸮰�,
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
			if (j < cost[i])	dp[i][j] = dp[i - 1][j];//i��° ����� �� ũ�ٸ� i��°���� ���� ����.
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);//����X->������ �״��, �����ϸ� ������ ����� ���ְ� �޸� ������.
			}

			if (dp[i][j] >= m && j < result)//m����Ʈ �̻� Ȯ����, �� �� ����� �ּڰ��� ���Ѵ�.
				result = j;
		}
	}

	cout << result << "\n";

	return 0;
}