#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int map[510][510];
int dp[510][510];//(y,x)에서 탈출 할 수 있는지, 1이 탈출 가능
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int isEscape(int y, int x)//dp+dfs
{
	if (y < 0 || x < 0 || y >= N || x >= M)	return 1;
	int &ret = dp[y][x];
	if (ret != -1)	return ret;

	dp[y][x] = 0;
	int d = map[y][x];

	dp[y][x] = isEscape(y + dy[d], x + dx[d]);

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	char c;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			if (c == 'U')	map[i][j] = 0;
			else if (c == 'R')	map[i][j] = 1;
			else if (c == 'D')	map[i][j] = 2;
			else if (c == 'L')	map[i][j] = 3;

			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cnt += isEscape(i, j);
		}
	}

	cout << cnt << "\n";

	return 0;
}