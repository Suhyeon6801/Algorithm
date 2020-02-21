#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 110;
int map[MAX][MAX];
int copyMap[MAX][MAX];
bool visit[MAX][MAX];
int check[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int N;

void copyArea()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyMap[i][j] = map[i][j];
		}
	}
}

void dfs(int y, int x, int a)
{
	visit[y][x] = true;
	check[y][x] = a;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		
		if (!visit[ny][nx] && copyMap[ny][nx] != 0)
		{
			check[ny][nx] = a;
			dfs(ny, nx, a);
		}
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int maxHeight = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (maxHeight < map[i][j])
				maxHeight = map[i][j];
		}
	}

	int getMax = 1;
	for (int k = 1; k <= maxHeight; k++)
	{
		//map복사
		copyArea();

		//k이하의 지점은 모두 0으로 표기
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (copyMap[i][j] <= k)
					copyMap[i][j] = 0;
			}
		}

		memset(check, 0, sizeof(check));
		memset(visit, 0, sizeof(visit));

		////dfs로 영역 개수 세고 최대 개수 갱신
		int area = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j] && copyMap[i][j] != 0)
				{
					dfs(i, j, area);
					area++;
				}
			}
		}
		getMax = max(getMax, area - 1);
	}

	cout << getMax << "\n";

	return 0;
}