#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 60;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

int bfs(int y, int x)
{
	int room_size = 0;
	queue<pair<int, int>> que;
	que.push({ y,x });
	visit[y][x] = true;
	
	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		room_size++;

		int wall = 1;
		for (int i = 0; i < 4; i++)
		{
			if ((map[y][x] & wall) != wall)//&연산했을 때 똑같은 값이 나오면 벽이 있다는 뜻, 아니면 벽 없다!
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 | ny >= m || nx >= n)	continue;

				if (!visit[ny][nx])
				{
					visit[ny][nx] = true;
					que.push({ ny,nx });
				}
			}
			wall = wall * 2;
		}
	}

	return room_size;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;//m이 세로, n이 가로
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int room_cnt = 0;
	int max_room = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				max_room = max(max_room, bfs(i, j));
				room_cnt++;
			}
		}
	}

	cout << room_cnt << "\n";
	cout << max_room << "\n";

	int max_room2 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int wall = 1; wall <= 8; wall *= 2)
			{
				if ((map[i][j])&wall == wall)
				{
					memset(visit, 0, sizeof(visit));
					map[i][j] -= wall;
					max_room2 = max(max_room2, bfs(i, j));
					map[i][j] += wall;
				}
			}
		}
	}

	cout << max_room2 << "\n";

	return 0;
}