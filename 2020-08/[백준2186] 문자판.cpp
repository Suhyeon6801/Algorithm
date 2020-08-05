#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, M, K;
string map[110];
string str;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int dp[110][110][110];//(i,j)에 존재하는 알파벳일 때 찾을 문자가 k번째 인덱스 일때의 갯수.

int dfs(int y, int x, int idx)
{
	if (idx >= str.length())	return 1;
	int &ret = dp[y][x][idx];
	if (ret != -1)
		return ret;

	dp[y][x][idx] = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int ny = y + dy[i] * j;
			int nx = x + dx[i] * j;

			if (ny < 0 || nx < 0 || ny >= N || nx >= M ||map[ny][nx]!=str[idx])	continue;

			dp[y][x][idx] += dfs(ny, nx, idx + 1);
		}
	}

	return dp[y][x][idx];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	cin >> str;

	memset(dp, -1, sizeof(dp));

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == str[0])
				cnt += dfs(i, j, 1);
		}
	}

	cout << cnt << "\n";

	return 0;
}