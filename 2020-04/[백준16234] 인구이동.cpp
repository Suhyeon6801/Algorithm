#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N, L, R;
int map[60][60];
bool visit[60][60];
vector<pair<int, int>> v;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int num = 0, pepole = 0;

void dfs(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		else
		{
			int diff = abs(map[y][x] - map[ny][nx]);
			if ((diff >= L && diff <= R)&& !visit[ny][nx])
			{
				v.push_back(make_pair(ny, nx));
				num++;
				pepole += map[ny][nx];
				dfs(ny, nx);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	bool flag = true;
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	while (1)
	{
		memset(visit, 0, sizeof(visit));

		flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j])	continue;

				v.clear();
				v.push_back(make_pair(i, j));
				num = 1;
				pepole = map[i][j];
				dfs(i, j);

				if (num >= 2)
				{
					flag = true;

					int result = pepole / num;;
					for (int i = 0; i < v.size(); i++)
					{
						int y = v[i].first;
						int x = v[i].second;
						map[y][x] = result;
					}
				}

			}
		}

		if (flag)	ans++;
		else
			break;
	}

	cout << ans << "\n";

	return 0;
}