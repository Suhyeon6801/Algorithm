#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[60][60];
int N, M;
bool visit[60][60];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs(int height)
{
	memset(visit, 0, sizeof(visit));
	queue<pair<int, int>> que;
	visit[0][0] = true;
	map[0][0] = height;
	que.push({ 0,0 });

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny > N + 1 || nx > M + 1)	continue;
			
			if (!visit[ny][nx] && map[ny][nx] < height)
			{
				visit[ny][nx] = true;
				map[ny][nx] = height;
				que.push({ ny,nx });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(map, 0, sizeof(map));
	char c;
	int maxHeight = -1, result = 0;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> c;
			map[i][j] = c - '0';

			if (map[i][j] > maxHeight)
				maxHeight = map[i][j];
		}
	}

	for (int h = 1; h <= maxHeight; h++)
	{
		bfs(h);

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (map[i][j] < h)
				{
					result += 1;
					map[i][j] += 1;
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}