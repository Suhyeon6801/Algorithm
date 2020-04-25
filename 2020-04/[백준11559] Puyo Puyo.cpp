#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

char map[12][6];
bool visit[12][6];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> boom_pos;

void print()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int dfs(int y, int x, char color)
{
	int ret = 1;
	visit[y][x] = true;
	boom_pos.push_back(make_pair(y, x));

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || 
			visit[ny][nx] || map[ny][nx] == '.'||map[ny][nx]!=color)	continue;

		ret += dfs(ny, nx, color);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> map[i][j];

	bool isBoom = false;
	int cnt = 0;
	vector<pair<int, int>> boom;

	while (1)
	{
		isBoom = false;
		memset(visit, 0, sizeof(visit));
		boom.clear();

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.' && !visit[i][j])
				{
					int temp = dfs(i, j, map[i][j]);

					if (temp >= 4)
					{
						isBoom = true;

						for (int k = 0; k < boom_pos.size(); k++)
							boom.push_back({ boom_pos[k].first, boom_pos[k].second });
					}

					boom_pos.clear();
				}
			}
		}

		for (int k = 0; k < boom.size(); k++)
		{
			int y = boom[k].first;
			int x = boom[k].second;

			map[y][x] = '.';
		}

		/*cout << "폭발\n";
		print();*/

		for (int k = 10; k >= 0; k--)
		{
			for (int l = 0; l < 6; l++)
			{
				if (map[k][l] != '.')
				{
					int idx = k;

					while (1)
					{
						if (idx == 11 || map[idx + 1][l] != '.')	break;

						map[idx + 1][l] = map[idx][l];
						map[idx][l] = '.';
						idx++;
					}
				}
			}
		}

		//print();

		if (isBoom)	cnt++;
		else
			break;
	}

	cout << cnt << "\n";

	return 0;
}