#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 60;
int r, c;
char map[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue<pair<int, int>>que;
int dist = 0;

void bfs(int y, int x)
{
	que.push(make_pair(y, x));
	visit[y][x] = true;

	while (!que.empty())
	{
		int size = que.size();
		while (size--)
		{
			int curY = que.front().first;
			int curX = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = curY + dy[i];
				int nx = curX + dx[i];

				if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] == 'W')	continue;
				if (!visit[ny][nx])
				{
					visit[ny][nx] = true;
					que.push(make_pair(ny, nx));
				}
			}
		}
		dist++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int getMax = -1;
	cin >> r >> c;//r 세로, c 가로
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j]=='L'&& !visit[i][j])
			{
				bfs(i, j);

				if (getMax < dist)	getMax = dist;
				dist = 0;
				memset(visit, 0, sizeof(visit));
			}
		}
	}

	cout << getMax - 1 << "\n";
	
	return 0;
}