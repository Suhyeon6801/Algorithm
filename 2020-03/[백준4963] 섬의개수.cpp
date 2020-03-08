#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 60;
int dy[8] = { 0,1,0,-1,1,1,-1,-1 };
int dx[8] = { 1,0,-1,0,1, - 1,1,-1 };
int map[MAX][MAX];
bool visit[MAX][MAX];
int w, h;

void search(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= h || nx >= w)	continue;
		else
		{
			if (!visit[ny][nx] && map[ny][nx] == 1)
				search(ny, nx);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)	break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}

		int island = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visit[i][j] && map[i][j] == 1)
				{
					search(i, j);
					island++;
				}
			}
		}

		cout << island << "\n";

		memset(visit, 0, sizeof(visit));
	}

	return 0;
}