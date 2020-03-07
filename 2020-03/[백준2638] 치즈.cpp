#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 110;

int cheeze[MAX][MAX];
bool visit[MAX][MAX];
int N, M;
int check[MAX][MAX];
queue<pair<int, int>> que;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs()
{
	while (!que.empty())
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visit[ny][nx])	continue;

			if (cheeze[ny][nx] == 1)
				check[ny][nx]++;
			else
			{
				que.push(make_pair(ny, nx));
				visit[ny][nx] = true;
			}
			
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] >= 2)
				cheeze[i][j] = 0;
		}
	}
}

bool melt_all()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cheeze[i][j] == 1)
				return false;
		}
	}

	return true;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int _time = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> cheeze[i][j];
		}
	}

	while (1)
	{
		que.push(make_pair(0, 0));
		visit[0][0] = true;
		bfs();
		_time++;

		if (melt_all())
			break;

		//초기화
		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
	}

	cout << _time << "\n";


	return 0;
}