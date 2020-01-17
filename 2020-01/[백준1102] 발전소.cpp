/*
현재 고장나 있지 않은 발전소 목록을 매개변수로 넘기면서,
2중 for문으로 안 고장난 i번 발전소가 고장난 j번 발전소를 고치는 경우를 다 시도해 보고
그때마다 아직도 남은 발전소들을 고치는 최소 비용을 찾는 DP
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int dp[1 << 16];
int cost[16][16];
int cnt = 0;
int n, p;

int func(int operand)
{
	int &ret = dp[operand];
	if (ret != -1)	return ret;
	if (cnt >= p)	return ret = 0;

	ret = INF;
	cnt++;
	for (int i = 0; i < n; i++)
	{
		if (operand&(1 << i))//고장나지 않은 발전소
		{
			for (int j = 0; j < n; j++)
			{
				if (!(operand&(1 << j)))//고장난 발전소
				{
					ret = min(ret, func(operand | (1 << j)) + cost[i][j]);
				}
			}
		}
	}
	cnt--;
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}

	int operand = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'Y')
		{
			cnt++;
			operand |= 1 << i;
		}
	}
	cin >> p;

	memset(dp, -1, sizeof(dp));

	int result = func(operand);
	if (result == INF)	cout << "-1\n";
	else
		cout << result << "\n";
	return 0;
}[]