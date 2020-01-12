#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 60;
char map[MAX][MAX];
bool visit[MAX][MAX];
int height[MAX][MAX];
vector<int> h;
int n;
int py, px;
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int high = 0, low = 0;
int result = 987654321;
void dfs(int y, int x)
{
	if (y < 0 || x < 0 || x >= n || y >= n || visit[y][x])	return;
	if (height[y][x]<h[low] || height[y][x]>h[high])	return;

	visit[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];	
		dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'P')
			{
				py = i, px = j;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> height[i][j];
			h.push_back(height[i][j]);
		}
	}

	sort(h.begin(), h.end());

	while (high < n*n)
	{
		memset(visit, 0, sizeof(visit));
		dfs(py, px);
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visit[i][j]&&map[i][j] == 'K')
				{
					flag = true;
					visit[i][j] = false;
				}
			}
		}
		if (flag)
		{
			high++;
		}
		else
		{
			result = min(result, h[high] - h[low]);
			low++;
		}
	}
	cout << result << "\n";

	return 0;
}