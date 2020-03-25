#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int map[10][10];
int curLab[10][10];//map복사
int temp[10][10];
bool visit[10][10];
int N, M;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int getMax = -1;

void bfs()//바이러스 퍼트리고 안전지역 검사
{
	memset(visit, 0, sizeof(visit));
	memset(temp, 0, sizeof(temp));

	queue<pair<int, int>> que;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = curLab[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 2)
			{
				que.push(make_pair(i, j));
				visit[i][j] = true;
			}
			else if (temp[i][j] == 1)
				visit[i][j] = true;
		}
	}

	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
			else
			{
				if (temp[ny][nx] == 0 && !visit[ny][nx])
				{
					que.push(make_pair(ny, nx));
					temp[ny][nx] = 2;
					visit[ny][nx] = true;
				}
			}
		}
	}

	int safety = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0)
				safety++;
		}
	}

	getMax = max(safety, getMax);
}

void f(int cnt)//벽 3개 되면 bfs돌림.
{
	if (cnt == 3)
	{
		bfs();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (curLab[i][j] == 0)
			{
				curLab[i][j] = 1;
				f(cnt + 1);
				curLab[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < M; l++)
					{
						curLab[k][l] = map[k][l];
					}
				}

				curLab[i][j] = 1;//벽세우고
				f(1);//벽 세우기 함수 돌리고
				curLab[i][j] = 0;//초기화해준다.
			}
		}
	}

	cout << getMax << "\n";

	return 0;
}