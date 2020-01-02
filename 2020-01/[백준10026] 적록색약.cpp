#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 110;
char map[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n;

void dfs(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
		if ((map[ny][nx] == map[y][x])&&!visit[ny][nx])
			dfs(ny, nx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt1 = 0, cnt2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				dfs(i, j);
				cnt1++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'G')
			{
				map[i][j] = 'R';
			}
		}
	}

	memset(visit, 0, sizeof(visit));


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				dfs(i, j);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2 << "\n";
	
	return 0;
}
