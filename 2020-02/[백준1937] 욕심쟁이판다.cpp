#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 510;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int map[MAX][MAX];
int dp[MAX][MAX];//i,j까지 움직였을 때 살 수 있는 최대 일수
int N;

int solve(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)	return 0;//범위 벗어나가면 끝
	int& ret = dp[y][x];
	if (ret != -1)
		return ret;

	dp[y][x] = 1;//그 자리에서 살 수 있는 일수
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (map[ny][nx] > map[y][x])
			dp[y][x] = max(dp[y][x], solve(ny, nx) + 1);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	int K = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			K = max(K, solve(i, j));
		}
	}

	cout << K << "\n";
	
	return 0;
}