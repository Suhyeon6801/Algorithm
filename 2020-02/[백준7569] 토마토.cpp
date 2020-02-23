#include <iostream>
#include <queue>
using namespace std;

const int MAX = 110;
struct Tomato {
	int x, y, z;
};
int box[MAX][MAX][MAX];
int dy[6] = { 1,-1,0,0,0,0 };
int dx[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
bool visit[MAX][MAX][MAX];
int check[MAX][MAX][MAX];
int M, N, H;//M가로,N세로,H높이
queue <Tomato> que;
int ripe, noripe, tomato;
int days = 0;
d
Tomato make_node(int a, int b, int c)
{
	Tomato temp;

	temp.y = a;
	temp.x = b;
	temp.z = c;

	return temp;
};

int bfs()
{
	while (!que.empty())
	{
		int size = que.size();

		while (size--)
		{
			int y = que.front().y;
			int x = que.front().x;
			int z = que.front().z;
			que.pop();

			for (int i = 0; i < 6; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				int nz = z + dz[i];

				//if (box[ny][nx][nz] == -1) break;
				if (ny < 1 || nx < 1 || nz < 1 || ny > N || nx > M || nz > H ||box[ny][nx][nz]!=0)	continue;
				else
				{
					if (!visit[ny][nx][nz])
					{
						visit[ny][nx][nz] = true;
						check[ny][nx][nz] = 1;
						que.push(make_node(ny, nx, nz));
						noripe--;
					}
				}
			}			
		}
		days++;
	}

	if (noripe == 0)
		return days;
	else
		return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;

	
	for (int k = 1; k <= H; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cin >> box[i][j][k];

				if (box[i][j][k] == 1)
				{
					que.push(make_node(i, j, k));
					visit[i][j][k] = true;
					check[i][j][k] = 1;
					ripe++;
				}

				if (box[i][j][k] == 0)
					noripe++;
			}
		}
	}

	int result = bfs();

	if (result == -1)
		cout << "-1\n";
	else
		cout << result - 1 << "\n";
	return 0;
}