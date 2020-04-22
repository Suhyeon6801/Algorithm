#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 60;
int R, C, T;
int map[MAX][MAX];
int arr[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
pair<int, int> Air[2];//공기청정기 위치, 0은 위, 1은 아래

void CopyMap()
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			arr[i][j] = map[i][j];
}

void print(int a[MAX][MAX])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Diffuion()//미세먼지 확산
{
	CopyMap();

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] !=0&&map[i][j]!=-1)
			{
				int cnt = 0;
				int val = map[i][j] / 5;

				for (int dir = 0; dir < 4; dir++)
				{
					int ny = i + dy[dir];
					int nx = j + dx[dir];

					if (ny < 0 || nx < 0 || ny >= R || nx >= C)	continue;
					else
					{
						if (arr[ny][nx] != -1)
						{
							arr[ny][nx] += val;
							cnt++;
						}
					}
				}

				arr[i][j] = arr[i][j] - (val * cnt);
			}
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			map[i][j] = arr[i][j];
}

void AirCleanerStart()//공기청정기 작동
{
	int temp[60] = { 0, };
	for (int k = 0; k < 2; k++)
	{
		int y = Air[k].first;
		int x = Air[k].second;

		if (k == 0)//위->반시계방향
		{
			//나머지는 한칸씩 이동.
			for (int i = y - 1; i > 0; i--)
				map[i][x] = map[i - 1][x];

			for (int i = 0; i < C - 1; i++)
				map[0][i] = map[0][i+1];

			for (int i = 0; i < y; i++)
				map[i][C - 1] = map[i + 1][C - 1];

			for (int i = C - 1; i > x+1; i--)
				map[y][i] = map[y][i-1];

			map[y][x + 1] = 0;

		}
		else//아래=>시계방향
		{
			for (int i = y + 1; i <R-1; i++)
				map[i][x] = map[i+1][x];

			//cout << "▼\n";
			//print(map);
			
			for (int i = 0; i < C - 1; i++)
				map[R - 1][i] = map[R - 1][i+1];

			//cout << "◀\n";
			//print(map);

			for (int i = R - 1; i > y; i--)
				map[i][C - 1] = map[i - 1][C - 1];

			//cout << "▲\n";
			//print(map);

			for (int i = C - 1; i > x+1; i--)
				map[y][i] = map[y][i - 1];
			//cout << "▶\n";
			//print(map);

			map[y][x + 1] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int idx = 0;

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == -1)
			{
				Air[idx].first = i;
				Air[idx].second = j;
				idx++;
			}
		}
	}

	for(int i=0; i<T; i++)
	{
		Diffuion();
		AirCleanerStart();
	}

	int result = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != -1)
				result += map[i][j];
		}
	}

	cout << result << "\n";

	return 0;
}