#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 60;
const int INF = 987654321;
int map[MAX][MAX];
bool visit[MAX][MAX];
int check[MAX][MAX];
vector<pair<int, int>> virus;
vector<pair<int, int>> v;
bool isSelect[MAX];
int N, M;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int getMin = INF;
int uninfect = 0;

void bfs()
{
	queue<pair<int, int>> que;

	for (int i = 0; i < v.size(); i++)
	{
		int y = v[i].first;
		int x = v[i].second;
		que.push({ y, x });
		visit[y][x] = true;
		check[y][x] = 0;
	}

	int cnt = 0;
	int sec = 0;
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
				
				if (!visit[ny][nx] && map[ny][nx]!=1 && check[ny][nx] == -1)
				{
					visit[ny][nx] = true;
					check[ny][nx] = check[y][x] + 1;
					if (map[ny][nx] == 0)
					{
						cnt++;
						sec = check[ny][nx];
					}
					que.push({ ny,nx });
				}
			}
		}
	}

	if (uninfect == cnt)
		getMin = min(getMin, sec);

}

void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		memset(visit, 0, sizeof(visit));
		memset(check, -1, sizeof(check));
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++)
	{
		if (!isSelect[i])
		{
			isSelect[i] = true;
			v.push_back({ virus[i].first, virus[i].second });
			dfs(i, cnt + 1);
			v.pop_back();
			isSelect[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)
				virus.push_back({ i,j });
			else if (map[i][j] == 0)
				uninfect++;
		}
	}

	dfs(0, 0);

	if (getMin == INF)	getMin = -1;

	cout << getMin << "\n";

	return 0;
}