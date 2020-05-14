#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 40;
const int INF = 987654321;
char map[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int dz[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dx[6] = { 0,0,0,0,1,-1 };
struct Pos {
	int z, y, x;
};

Pos make_node(int a, int b, int c){
	Pos p;
	p.z = a, p.y = b, p.x = c;
	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int L, R, C;
	while (1)
	{
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
			break;

		memset(visit, 0, sizeof(visit));
		int sz, sy, sx, ez, ey, ex;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> map[i][j][k];

					if (map[i][j][k] == 'S')
					{
						sz = i, sy = j, sx = k;
					}

					if (map[i][j][k] == 'E')
					{
						ez = i, ey = j, ex = k;
					}
				}
			}
		}

		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
				for (int k = 0; k < C; k++)
					dist[i][j][k] = INF;

		queue<Pos> que;
		que.push(make_node(sz, sy, sx));
		visit[sz][sy][sx] = true;
		dist[sz][sy][sx] = 0;

		while (!que.empty())
		{
			int z = que.front().z;
			int y = que.front().y;
			int x = que.front().x;
			que.pop();

			for (int i = 0; i < 6; i++)
			{
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (nz < 0 || ny < 0 || nx < 0 || nx >= C || ny >= R || nz >= L || map[nz][ny][nx] == '#' || visit[nz][ny][nx])
					continue;
				else
				{
					if (dist[nz][ny][nx] > dist[z][y][x] + 1)
					{
						visit[nz][ny][nx] = true;
						dist[nz][ny][nx] = dist[z][y][x] + 1;
						que.push(make_node(nz, ny, nx));
					}
				}
			}
		}

		//cout << dist[ez][ey][ex] << "\n";

		if (dist[ez][ey][ex] >= INF)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << dist[ez][ey][ex] << " minute(s).\n";
	}

	return 0;
}