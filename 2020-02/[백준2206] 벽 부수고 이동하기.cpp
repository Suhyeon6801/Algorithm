#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1010;
struct Point {
	int y, x, isBreak;
};

Point make_node(int a, int b, int c)
{
	Point temp;
	temp.y = a;
	temp.x = b;
	temp.isBreak = c;
	return temp;
}
queue <Point> que;
int N, M;
int map[MAX][MAX];
int visit[MAX][MAX][2];//0은 안깬거, 1은 깬거.
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int bfs(int y, int x, int isBreak)
{
	while (!que.empty())
	{
		int curY = que.front().y;
		int curX = que.front().x;
		int curBreak = que.front().isBreak;
		que.pop();

		if (curX == M - 1 && curY == N - 1)
			return visit[curY][curX][curBreak];

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
			else
			{
				//벽이 있고, 안뚫었음.
				if (map[ny][nx] == 1 && curBreak==0)
				{
					visit[ny][nx][curBreak+1] = visit[curY][curX][curBreak] + 1;//뚫음 표시해주고 +1
					que.push(make_node(ny, nx, curBreak + 1));
				}

				//벽이 없고 방문 안한곳
				if (map[ny][nx] == 0 && visit[ny][nx][curBreak]==0)
				{
					visit[ny][nx][curBreak] = visit[curY][curX][curBreak] + 1;
					que.push(make_node(ny, nx, curBreak));
				}
			}
		}
	}

	return -1;//다 돌고도 갈 수 없으면 불가능
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;

			map[i][j] = c - '0';
		}
	}

	que.push(make_node(0,0,0));
	visit[0][0][0] = 1;
	cout << bfs(0, 0, 0) << "\n";

	return 0;
}