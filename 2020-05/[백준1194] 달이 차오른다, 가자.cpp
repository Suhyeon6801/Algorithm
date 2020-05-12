#include <iostream>
#include <queue>
using namespace std;

const int MAX = 60;
int N, M;
char map[MAX][MAX];
bool visit[MAX][MAX][1 << 6];
struct Info {
	int y, x, cnt, key;
};
Info make_node(int a, int b, int c, int d)
{
	Info temp;
	temp.y = a;
	temp.x = b;
	temp.cnt = c;
	temp.key = d;
	return temp;
}
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool isOpen(int key, char door)
{
	int temp = key & (1 << ((int)door - 'A'));

	if (temp != 0)
		return true;
	else
		return false;
}

int bfs(int y, int x)
{
	queue<Info> que;
	que.push(make_node(y, x, 0, 0));
	visit[y][x][0] = true;

	while (!que.empty())
	{
		int curY = que.front().y;
		int curX = que.front().x;
		int curCnt = que.front().cnt;
		int curKey = que.front().key;
		que.pop();

		if (map[curY][curX] == '1')
			return curCnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx][curKey] || map[ny][nx] == '#')	continue;

			if (map[ny][nx] == '.' || map[ny][nx] == '1')
			{
				que.push(make_node(ny, nx, curCnt + 1, curKey));
				visit[ny][nx][curKey] = true;
			}
			else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f')
			{
				int newKey = curKey | (1 << (int)(map[ny][nx] - 'a'));//키 주우면 OR연산
				visit[ny][nx][newKey] = true;
				que.push(make_node(ny, nx, curCnt + 1, newKey));
			}
			else if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F')
			{
				if (isOpen(curKey, map[ny][nx]))
				{
					visit[ny][nx][curKey] = true;
					que.push(make_node(ny, nx, curCnt + 1, curKey));
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sy, sx;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '0')
			{
				sy = i, sx = j;
				map[i][j] = '.';
			}
		}
	}

	cout << bfs(sy, sx) << "\n";

	return 0;
}