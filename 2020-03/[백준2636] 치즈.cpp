#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 110;

int map[MAX][MAX];
int check[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int melt_cnt[MAX];
int idx = 0;
queue<pair<int, int>> que;

int bfs()//녹을 부분 체크
{
	int cnt = 0;
	memset(check, 0, sizeof(check));

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])	continue;

			if (map[ny][nx] == 1)
			{
				check[ny][nx] = 1;
	
			}
			else
			{
				que.push(make_pair(ny, nx));
				visit[ny][nx] = true;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == 1)
				map[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)	cnt++;
		}
	}

	return cnt;
}

bool melt_all()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)	cnt++;
		}	
	}

	if (cnt == 0)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cheeze = 0;
	int melt_time = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 1)
				cheeze++;
		}
	}

	melt_cnt[idx++] = cheeze;

	while (1)
	{
		if (melt_all())	break;

		memset(visit, 0, sizeof(visit));
		que.push(make_pair(0, 0));
		visit[0][0] = true;
		melt_cnt[idx++]=bfs();
		melt_time++;
	}

	cout << melt_time << "\n";
	cout << melt_cnt[idx - 2] << "\n";

	return 0;
}