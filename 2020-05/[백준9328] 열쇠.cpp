#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int MAX = 110;
char map[MAX][MAX];
bool visit[MAX][MAX];
int isHave[26];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int h, w, result = 0;

void OpenDoor(int keyNum)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			char door = keyNum + 'A';

			if (map[i][j] == door)
				map[i][j] = '.';
		}
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> que;
	que.push({ 0,0 });
	visit[y][x] = true;

	while (!que.empty())
	{
		int curY = que.front().first;
		int curX = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny<0 || nx<0 || ny>h + 1 || nx>w + 1 || map[ny][nx] == '*' || visit[ny][nx]
				|| (map[ny][nx] >= 'A'&& map[ny][nx] <= 'Z'))	continue;

			if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z')
			{
				int getkey = map[ny][nx] - 'a';
				map[ny][nx] = '.';

				if (isHave[getkey] == 0)
				{
					isHave[getkey] = 1;
					OpenDoor(getkey);

					memset(visit, 0, sizeof(visit));//잠긴문 열었으니까 다시 경로 보자!!
					while (!que.empty())
						que.pop();

					que.push({ ny,nx });
					continue;
				}
			}
			else if (map[ny][nx] == '$')
			{
				result++;
				visit[ny][nx] = true;
				map[ny][nx] = '.';
				que.push({ ny,nx });
			}
			else if (map[ny][nx] == '.')
			{
				visit[ny][nx] = true;
				que.push({ ny,nx });
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		memset(isHave, 0, sizeof(isHave));
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		string keys;
		result = 0;

		cin >> h >> w;

		for (int i = 0; i <= h + 1; i++)
		{
			map[i][0] = '.';
			map[i][w + 1] = '.';
		}

		for (int j = 0; j <= w + 1; j++)
		{
			map[0][j] = '.';
			map[h + 1][j] = '.';
		}

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				cin >> map[i][j];

		cin >> keys;

		if (keys != "0")
		{
			for (int i = 0; i < keys.length(); i++)
			{
				int temp = keys[i] - 'a';
				isHave[temp] = 1;
				OpenDoor(temp);
			}
		}

		bfs(0, 0);
		cout << result << "\n";
	}

	return 0;
}