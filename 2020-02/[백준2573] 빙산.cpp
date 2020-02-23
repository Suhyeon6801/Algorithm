#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 310;
int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
bool check[MAX][MAX];
int waterCnt[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> que;

//빙산덩어리 개수 반환
void dfs(int y, int x, int count)
{
	check[y][x] = count;
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;

		if (!visit[ny][nx] && map[ny][nx] != 0)
		{
			check[ny][nx] = count;
			dfs(ny, nx, count);
		}
	}
}

//빙하 녹는 함수
void melt()
{
	memset(waterCnt, 0, sizeof(waterCnt));
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

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
			if (map[ny][nx] == 0)
				waterCnt[y][x]++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			map[i][j] -= waterCnt[i][j];

			if (map[i][j] <= 0)
				map[i][j] = 0;
			else
				que.push(make_pair(i, j));
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
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] != 0)
				que.push(make_pair(i, j));
		}
	}

	int days = 0;
	bool flag = true;
	while (1)
	{
		melt();

		days++;
		memset(visit, 0, sizeof(visit));
		int cnt = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && map[i][j] != 0)
					dfs(i, j, cnt++);
			}
		}
		cnt--;

		if (cnt == 0)
		{
			flag = false;
			break;
		}

		if (cnt >= 2)	break;
	}

	if (!flag)
		cout << "0\n";
	else
		cout << days << "\n";

	return 0;
}