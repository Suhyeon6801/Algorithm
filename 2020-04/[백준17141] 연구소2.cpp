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
vector<pair<int, int>> virus;
vector<pair<int, int>> select_virus;
bool isSelect[MAX];
int N, M;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int getMin = INF;

bool isAllSpread()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)	continue;
			if (!visit[i][j])	return false;
		}
	}
	return true;
}

void bfs()
{
	queue<pair<int, int>> que;

	for (int i = 0; i < select_virus.size(); i++)
	{
		int y = select_virus[i].first;
		int x = select_virus[i].second;
		que.push({ y, x });
		visit[y][x] = true;
	}

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
				else
				{
					if (!visit[ny][nx] && map[ny][nx] != 1)
					{
						visit[ny][nx] = true;
						que.push({ ny,nx });
					}
				}
			}
		}
		
		if (que.size() != 0)	sec++;
	}

	if (isAllSpread())	
		getMin = min(getMin, sec);
}

void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		memset(visit, 0, sizeof(visit));
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++)
	{
		if (!isSelect[i])
		{
			isSelect[i] = true;
			select_virus.push_back({ virus[i].first, virus[i].second });
			dfs(i, cnt + 1);
			select_virus.pop_back();
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
		}
	}

	dfs(0, 0);

	if (getMin == INF)	getMin = -1;

	cout << getMin << "\n";

	return 0;
}