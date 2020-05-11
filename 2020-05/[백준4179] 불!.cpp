#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1010;
char map[MAX][MAX];
bool visit[MAX][MAX];
int R, C;
queue<pair<int, int>> fire;
queue<pair<int, int>> jihun;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int bfs()
{
	int time = 0;
	while (!jihun.empty())
	{
		int sizeFire = fire.size();
		while (sizeFire--)
		{
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && nx >= 0 && ny < R&&nx < C)
				{
					if (map[ny][nx] == '.')
					{
						map[ny][nx] = 'F';
						fire.push({ ny,nx });
					}
				}
			}
		}

		int sizeJH = jihun.size();
		while (sizeJH--)
		{
			int y = jihun.front().first;
			int x = jihun.front().second;
			jihun.pop();

			if (y == 0 || x == 0 || y == R - 1 || x == C - 1)
			{
				return time + 1;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && nx >= 0 && ny < R&&nx < C)
				{
					if (!visit[ny][nx] && map[ny][nx] != '#'&&map[ny][nx] != 'F')
					{
						jihun.push({ ny,nx });
						visit[ny][nx] = true;
					}
				}
			}
		}
		time++;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'F')
				fire.push({ i,j });
			if (map[i][j] == 'J')
			{
				jihun.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	int result = bfs();

	if (result == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << result << "\n";

	return 0;
}