#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX = 110;
int M, N;
char maze[MAX][MAX];
int dist[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> maze[i][j];
			dist[i][j] = INF;
		}
	}

	dist[0][0] = 0;
	queue<pair<int, int>> que;
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

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;

			if (maze[ny][nx] == '1')
			{
				if (dist[ny][nx] > dist[y][x] + 1)
				{
					dist[ny][nx] = dist[y][x] + 1;
					que.push({ ny,nx });
				}
			}
			else
			{
				if (dist[ny][nx] > dist[y][x])
				{
					dist[ny][nx] = dist[y][x];
					que.push({ ny,nx });
				}
			}
		}
	}

	cout << dist[N - 1][M - 1] << "\n";
			
	return 0;
}