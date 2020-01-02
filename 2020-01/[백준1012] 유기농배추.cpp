#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 60;
int map[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k;

void dfs(int y, int x, int num)
{
	visit[y][x] = true;

	for (int k = 0; k < 4; k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];

		if (nx < 0 || ny < 0 || nx >= m || ny >= n)	continue;
		else
		{
			if (map[ny][nx] == 1 && !visit[ny][nx])
				dfs(ny, nx,num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int px, py;
		int cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visit, true, sizeof(visit));

		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			cin >> px >> py;

			map[py][px] = 1;
			visit[py][px] = false;
		}

		for (int i = 0; i < n; i++)//세로
		{
			for (int j = 0; j < m; j++)//가로
			{
				if (map[i][j]==1&&!visit[i][j])
				{
					dfs(i, j,cnt);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
	}
	

	return 0;
}
