#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 30;
char map[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };
int check[MAX][MAX] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n;

void dfs(int y, int x, int num)
{
	visit[y][x] = true;
	check[y][x] = num;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)	continue;
		if (!visit[ny][nx])
			dfs(ny, nx, num);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt = 0;
	int arr[MAX*MAX] = { 0, };//101010반복
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == '0')	visit[i][j] = true;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '1' && !visit[i][j])
			{
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[check[i][j]]++;
		}
	}

	sort(arr + 1, arr + 1 + cnt);

	cout << cnt << "\n";
	for (int i = 1; i <= cnt; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}
