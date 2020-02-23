#include <iostream>
#include <queue>
using namespace std;

struct Robot {
	int y, x, d;
};

Robot make_node(int a, int b, int c) {
	Robot temp;
	temp.y = a;
	temp.x = b;
	temp.d = c;
	return temp;
};
const int MAX = 60;
int map[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Robot robot;
	int cnt = 0;
	int y, x, d;
	cin >> N >> M;
	cin >> y >> x >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<Robot> que;
	que.push(make_node(y, x, d));
	visit[y][x] = true;
	cnt++;
	bool clean = false;

	while (!que.empty())
	{
		int curY = que.front().y;
		int curX = que.front().x;
		int curD = que.front().d;
		que.pop();

		//cout << curY << " " << curX << " " << curD << "\n";

		clean = false;
		for (int i = 0; i < 4; i++)
		{
			curD--;
			if (curD < 0)
				curD = 3;

			int ny = curY + dy[curD];
			int nx = curX + dx[curD];

			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if (map[ny][nx] == 0 && !visit[ny][nx])
				{
					visit[ny][nx] = true;
					cnt++;
					clean = true;
					que.push(make_node(ny, nx, curD));
				}
			}

			if (clean)
				break;
		}

		if (!clean)//네방향 다 청소 되어있는 경우
		{
			int ny = curY - dy[curD];
			int nx = curX - dx[curD];

			if (ny >= 0 && nx >= 0 && ny < N && nx < M && map[ny][nx] == 0)
			{
				que.push(make_node(ny, nx, curD));
			}
			else
				break;
		}
	}

	cout << cnt << "\n";

	return 0;
}