#include <iostream>
#include <queue>
using namespace std;
const int MAX = 110;

struct Robot {
	int y, x, d;
};

Robot make_node(int a, int b, int c)
{
	Robot temp;
	temp.y = a;
	temp.x = b;
	temp.d = c;

	return temp;
}

Robot robot[MAX];
int map[MAX][MAX];
int M, N;//M이 세로, N이 가로
int sy, sx, sd, ey, ex, ed;
queue<pair<Robot, int>> que;
bool visit[MAX][MAX][5];
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };//동-1, 서-2,남-3,북-4

void bfs()
{
	while (!que.empty())
	{
		int y = que.front().first.y;
		int x = que.front().first.x;
		int d = que.front().first.d;
		int cnt = que.front().second;
		que.pop();

		if (y == ey && x == ex && d == ed)
		{
			cout << cnt << "\n";
			return;
		}

		//Go K->현재 향하고 있는 방향으로 k만큼 움직인다.
		for (int k = 1; k <= 3; k++)
		{
			int ny = y + dy[d] * k;
			int nx = x + dx[d] * k;

			if (ny < 1 || nx < 1 || ny > M || nx > N || map[ny][nx] == 1)	break;
			else
			{
				if (!visit[ny][nx][d])
				{
					visit[ny][nx][d] = true;
					que.push(make_pair(make_node(ny, nx, d), cnt + 1));
				}
			}
		}

		//Turn dir
		for (int i = 1; i <= 4; i++)
		{
			if (i != d && !visit[y][x][i])//현재방향이랑 같은 방향이 아니고, visit하지 않았을 때
			{
				if ((d == 1 && i != 2) || (d == 2 && i != 1) || (d == 3 && i != 4) || (d == 4 && i != 3))//90도씩 회전
				{
					visit[y][x][i] = true;
					que.push(make_pair(make_node(y, x, i), cnt + 1));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	cin >> sy >> sx >> sd >> ey >> ex >> ed;

	visit[sy][sx][sd] = true;
	que.push(make_pair(make_node(sy, sx, sd), 0));
	bfs();

	return 0;
}