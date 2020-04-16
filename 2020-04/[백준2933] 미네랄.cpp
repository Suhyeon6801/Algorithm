#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 110;
int R, C, N;
char map[MAX][MAX];
int height[MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> cluster;
bool flag = false;//바닥에 닿았는지

void dfs(int y, int x)
{
	if (y == R)
	{
		flag = true;//바닥에 닿았다!
		return;
	}

	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<1 || nx<1 || ny>R || nx>C || map[ny][nx] == '.'|| visit[ny][nx])	continue;
		else
		{
			cluster.push_back(make_pair(ny, nx));
			dfs(ny, nx);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> map[i][j];
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> height[i];

	for (int i = 1; i <= N; i++)//미네랄 파괴
	{
		int y = R - height[i] + 1;
		int x = 0;

		if (i % 2 == 1)//왼->오
		{
			for (int j = 1; j <= C; j++)
			{
				if (map[y][j] == 'x')
				{
					x = j;
					break;
				}
			}
		}
		else//오->왼
		{
			for (int j = C; j >= 1; j--)
			{
				if (map[y][j] == 'x')
				{
					x = j;
					break;
				}
			}
		}

		if (x == 0)	continue;//미네랄 부술꺼 없음.
		
		map[y][x] = '.';//미네랄 부수고

		//주변 클러스터 확인
		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny<1 || nx<1 || nx>C || ny>R || map[ny][nx] == '.')	continue;

			cluster.clear();
			memset(visit, 0, sizeof(visit));
			flag = false;

			cluster.push_back(make_pair(ny, nx));
			dfs(ny, nx);//주변 클러스터 찾기

			if (!flag)//밑으로 이동
			{
				while (1)
				{
					bool isBottom = false;

					for (int j = 0; j < cluster.size(); j++)
					{
						int y = cluster[j].first;
						int x = cluster[j].second;

						map[y][x] = '.';
					}

					for (int j = 0; j < cluster.size(); j++)
					{
						int yy = cluster[j].first + 1;
						int xx = cluster[j].second;

						if (yy == R + 1 || map[yy][xx] == 'x')//바닥에 닿았거나, 다른 클러스트를 만나면 break
						{
							isBottom = true;
							break;
						}
					}

					for (int j = 0; j < cluster.size(); j++)
					{
						if (!isBottom)
							cluster[j].first++;

						map[cluster[j].first][cluster[j].second] = 'x';
					}

					if (isBottom)	break;
				}
			}
		}
	}

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}