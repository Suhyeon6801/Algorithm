#include <iostream>
#include <queue>
using namespace std;

const int MAX = 210;
int K, W, H;
int map[MAX][MAX];
bool visited[MAX][MAX][31];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int dy2[8] = { -1,1,-2,-2,-1,1,2,2 };
int dx2[8] = { -2,-2,-1,1,2,2,-1,1 };

struct Monkey {
	int y, x, move, cnt;
};

bool checkInside(int y, int x)
{
	return (y >= 0 && x >= 0 && x < W && y < H);
}

void bfs()
{
	queue<Monkey> que;
	visited[0][0][0] = true;
	que.push({ 0,0,0,0 });

	while (!que.empty())
	{
		int y = que.front().y;
		int x = que.front().x;
		int move = que.front().move;
		int cnt = que.front().cnt;
		que.pop();

		if (y == H - 1 && x == W - 1)
		{
			cout << move << "\n";
			return;
		}

		int ny, nx;

		for (int i = 0; i < 4; i++)
		{
			ny = y + dy[i];
			nx = x + dx[i];

			if (checkInside(ny, nx) && !visited[ny][nx][cnt] && map[ny][nx] == 0)
			{
				que.push({ ny,nx,move + 1,cnt });
				visited[ny][nx][cnt] = true;
			}
		}

		if (cnt < K)
		{
			for (int i = 0; i < 8; i++)
			{
				ny = y + dy2[i];
				nx = x + dx2[i];

				if (checkInside(ny, nx) && !visited[ny][nx][cnt+1] && map[ny][nx]==0)
				{
					que.push({ ny,nx,move + 1,cnt + 1 });
					visited[ny][nx][cnt+1] = true;
				}
			}
		}
	}

	cout << "-1\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> map[i][j];
		}
	}

	bfs();

	return 0;
}