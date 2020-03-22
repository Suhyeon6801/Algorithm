#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int map[110][110];
int island[110][110];
bool visit[110][110];//단지번호
bool check[110][110];//섬끼리 연결
int N;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans = 987654321;

void dfs(int y, int x, int num)
{
	visit[y][x] = true;
	island[y][x] = num;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		else
		{
			if (!visit[ny][nx] && map[ny][nx] == 1)
			{
				dfs(ny, nx, num);
			}
		}
	}
}

int bfs(int num)
{
	queue<pair<int, int>> que;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (island[i][j] == num)
			{
				check[i][j] = true;
				que.push(make_pair(i, j));
			}
		}
	}

	int dist = 0;
	while (!que.empty())
	{
		int size = que.size();
		while (size--)
		{
			int y = que.front().first;
			int x = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
				else 
				{
					//아직 방문 하지 않은 섬이고 현재 섬이 아닌경우
					if (island[ny][nx] != 0 && island[ny][nx] != num)
					{
						return dist;
					}
					else if (island[ny][nx] == 0 && !check[ny][nx])
					{
						que.push(make_pair(ny, nx));
						check[ny][nx] = true;
					}

				}
			}
		}
		dist++;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	//섬 표기
	int cnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				dfs(i, j, cnt);
				cnt++;
			}
		}
	}

	//섬 -> 섬으로 가는 다리 연결 최솟값
	for (int i = 1; i < cnt; i++)
	{
		memset(check, 0, sizeof(check));
		ans = min(ans,bfs(i));
	}

	cout << ans << "\n";
	
	return 0;
}