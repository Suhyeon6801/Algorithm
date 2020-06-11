#include <iostream>
#include <queue>
using namespace std;

const int MAX = 60;
char map[MAX][MAX];
bool visit[MAX][MAX][1 << 5];
int N, M;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int sy, sx, ey, ex;

struct Info {
	int y, x, sec, check;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;//가로의 길이가 N이다
	int stuff = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'S')
			{
				sy = i, sx = j;
			}
			else if (map[i][j] == 'X')
			{
				map[i][j] = stuff + '0';
				stuff++;
			}
			else if (map[i][j] == 'E')
			{
				ey = i, ex = j;
			}
		}
	}

	queue<Info> que;
	que.push({ sy,sx,0,0 });
	visit[sy][sx][0] = true;

	while (!que.empty())
	{
		int y = que.front().y;
		int x = que.front().x;
		int sec = que.front().sec;
		int check = que.front().check;
		que.pop();

		if ((y == ey && x == ex) && check == (1 << stuff) - 1)
		{
			cout << sec << "\n";
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= M || nx >= N || map[ny][nx] == '#')	continue;
			else
			{
				int nextCheck = check | (1 << map[ny][nx] - '0');

				if (map[ny][nx] >= '0'&& map[ny][nx] < '5')
				{
					if (!visit[ny][nx][nextCheck])
					{
						visit[ny][nx][nextCheck] = true;
						que.push({ ny,nx,sec + 1,nextCheck });
					}
				}

				if (!visit[ny][nx][check])
				{
					visit[ny][nx][check] = true;
					que.push({ ny,nx,sec + 1,check });
				}
			}
		}
	}

	return 0;
}