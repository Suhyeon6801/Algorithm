#include <iostream>
#include <queue>
using namespace std;

const int MAX = 110;
char map[MAX][MAX] = { 0, };
bool check[MAX][MAX] = { 0, };
int moveMap[MAX][MAX] = { 0, };
int n, m;
queue <pair<int, int>> que;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int y, int x)
{
	que.push(make_pair(y, x));
	check[y][x] = true;
	moveMap[y][x] = 1;

	while (!que.empty())
	{
		int curY = que.front().first;
		int curX = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 1 | nx<1 || ny>n || nx > m)	continue;

			if (!check[ny][nx])
			{
				que.push(make_pair(ny, nx));
				check[ny][nx] = true;
				moveMap[ny][nx] = moveMap[curY][curX] + 1;
			}
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '0')	check[i][j] = true;
		}
	}

	bfs(1, 1);

	cout << moveMap[n][m] << "\n";

	return 0;
}