#include <iostream>
using namespace std;

const int MAX = 110;
int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int cnt = 0;

int dfs(char c, int y, int x)
{
	visit[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
		else
		{
			if (map[ny][nx] == c && !visit[ny][nx])
				dfs(c, ny, nx);
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	int w = 0, b = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j])
			{
				int temp = dfs(map[i][j], i, j);
				cnt = 0;
				if (map[i][j] == 'W')
				{
					w += temp * temp;
				}
				else
				{
					b += temp * temp;
				}
				
			}
		}
	}

	cout << w << " " << b << "\n";

	return 0;
}