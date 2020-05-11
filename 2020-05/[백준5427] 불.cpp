#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1010;
char map[MAX][MAX];
bool visit[MAX][MAX];
int w, h;
queue<pair<int, int>> fire;
queue<pair<int, int>> sg;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int bfs()
{
	//불->상근이 이동
	int dist = 0;

	while (!sg.empty())
	{
		int size1 = fire.size();
		for (int k = 0; k < size1; k++)
		{
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && nx >= 0 && ny < h && nx < w)
				{
					if (map[ny][nx] == '.')
					{
						map[ny][nx] = '*';
						fire.push({ ny,nx });
					}
				}
			}
		}

		int size2 = sg.size();
		for (int k = 0; k < size2; k++)
		{
			int y = sg.front().first;
			int x = sg.front().second;
			sg.pop();

			if (y == 0 || x == 0 || y == h - 1 || x == w - 1)
			{
				return dist + 1;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= 0 && nx >= 0 && ny < h && nx < w)
				{
					if (!visit[ny][nx] && map[ny][nx] != '#' && map[ny][nx] != '*')
					{
						visit[ny][nx] = true;
						sg.push({ ny,nx });
					}
				}
			}
		}

		dist++;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		memset(visit, 0, sizeof(visit));

		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];

				if (map[i][j] == '@')
				{
					sg.push({ i,j });
				}

				if (map[i][j] == '*')
				{
					fire.push({ i,j });
				}
			}
		}

		int result = bfs();

		if (result == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << result << "\n";

		//비워주지 않았어!!! -> 이거 때에 엄청 틀려댐ㅠㅠ
		while (!sg.empty())
		{
			sg.pop();
		}

		while (!fire.empty())
		{
			fire.pop();
		}
	}

	return 0;
}