#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 110;
int map[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };
int check[MAX][MAX] = { 0, };
int m, n, k;//m세로, n가로
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void dfs(int y, int x, int num)
{
	visit[y][x] = true;
	check[y][x] = num;

	for (int t = 0; t < 4; t++)
	{
		int ny = y + dy[t];
		int nx = x + dx[t];

		if (ny < 0 || nx < 0 || ny >= m || nx >= n)	continue;
		else
		{
			if (!visit[ny][nx])
				dfs(ny, nx,num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x1, y1, x2, y2;
	int cnt = 0;
	int arr[MAX] = { 0 };

	cin >> m >> n >> k;

	for (int t = 0; t < k; t++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		y1 = m - y1;
		y2 = m - y2;

		for (int j = x1; j < x2; j++)
		{
			for (int i = y2; i < y1; i++)
			{
				map[i][j] = 1;
				visit[i][j] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0 && !visit[i][j])
			{
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}

	for (int t = 1; t <= cnt; t++)
	{
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] == t)	count++;
			}
		}
		arr[t] = count;
	}

	sort(arr+1, arr + cnt+1);//오름차순정렬

	cout << cnt << "\n";
	for (int t = 1; t <= cnt; t++)
	{
		cout << arr[t] << " ";
	}

	return 0;
}
