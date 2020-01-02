#include <iostream>
using namespace std;

char map[30][30] = { 0, };
char alpha_check[30] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int r, c;
int getMax = -1;

void dfs(int y, int x, int cnt)
{
	if (getMax < cnt)	getMax = cnt;

	alpha_check[map[y][x] - '0'] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c)	continue;

		if (!alpha_check[map[ny][nx] - '0'])
		{
			alpha_check[map[ny][nx] - '0'] = true;
			dfs(ny, nx, cnt + 1);
			alpha_check[map[ny][nx] - '0'] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	dfs(0, 0, 1);

	cout << getMax << "\n";

	return 0;
}