//DP+DFS(메모제이션)

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[510][510];//i,j까지 내려올수 있는 경우의 수
int map[510][510];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N, M;

int dfs(int y, int x)
{
	if (y<1 || x<1 || y>N || x>M)	return 0;

	int &ret = dp[y][x];
	if (ret != -1)	return ret;

	if (y == 1 && x == 1)	return 1;//기저조건

	dp[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(map[ny][nx]>map[y][x])
			dp[y][x] += dfs(ny, nx);
	}

	return dp[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(N, M) << "\n";

	return 0;
}