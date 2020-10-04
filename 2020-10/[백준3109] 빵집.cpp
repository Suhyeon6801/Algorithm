#include <iostream>
#include <cstring>
using namespace std;

char map[10010][510];
bool visit[10010][510];
int R, C;
int dy[3] = { -1,0,1 };
int dx[3] = { 1,1,1 };
int result = 0;
bool flag = false;

void dfs(int y, int x)
{
	visit[y][x] = true;

	if (x == C - 1)
	{
		flag = true;
		result++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C)	continue;
		if (!visit[ny][nx] && map[ny][nx] == '.')
		{
			if (flag) return;
			dfs(ny, nx);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
	{
		flag = false;//*파이프가 겹치면 안됨!
		dfs(i, 0);
	}

	cout << result << "\n";

	return 0;
}