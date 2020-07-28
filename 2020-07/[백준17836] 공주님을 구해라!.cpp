#include <iostream>
#include <queue>
using namespace std;

const int MAX = 110;
int N, M, T;
int map[MAX][MAX];
bool visited[MAX][MAX][2];//0은 그람안주웠을때, 1은 주웠을 때.
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool time_over = false;
int result = 0;

struct Info {
	int y, x, cnt, getGram;
};

bool check_boundary(int y, int x)
{
	return (y >= 0 && x >= 0 && x < M&&y < N);
}

void bfs()
{
	queue<Info> que;
	visited[0][0][0] = true;
	que.push({ 0,0,0,0 });

	while (!que.empty())
	{
		int y = que.front().y;
		int x = que.front().x;
		int cnt = que.front().cnt;
		int getGram = que.front().getGram;
		que.pop();

		if (cnt > T)	return;

		if (map[y][x] == 2)	getGram = 1;//그람 주었당!->주었다고 체크!
		if (y == N - 1 && x == M - 1)
		{
			result = cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (getGram == 1)//걍 뚫어버림.
			{
				if (check_boundary(ny, nx) && !visited[ny][nx][1])
				{
					visited[ny][nx][1] = true;
					que.push({ ny,nx,cnt + 1,1 });
				}
			}
			else
			{
				if (check_boundary(ny, nx) && !visited[ny][nx][0] && map[ny][nx] !=1)
				{
					visited[ny][nx][0] = true;
					que.push({ ny,nx,cnt + 1,0 });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	bfs();

	if (result>T||result<1)
		cout << "Fail\n";
	else
		cout << result << "\n";

	return 0;
}