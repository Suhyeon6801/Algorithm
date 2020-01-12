#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 60;
char map[MAX][MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX];
int n, m;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool flag = false;

int dfs(int y, int x)
{
	if (y < 0 || x < 0 || y >= n || x >= m || map[y][x] == 'H')	return 0;
	if (visit[y][x] && dp[y][x] == -1)	flag = true;//방문한 곳이고, 사이클이 생겼음. -> -1
	if (dp[y][x] != -1)	return dp[y][x];
	if (flag)	return -1;

	int result = 0;
	int k = map[y][x] - '0';
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * k;
		int nx = x + dx[i] * k;

		result = max(result,dfs(ny, nx));
	}

	if (flag)	return -1;
	return dp[y][x] = result + 1;//dp에 저장.
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0) << "\n";
	
	return 0;
}