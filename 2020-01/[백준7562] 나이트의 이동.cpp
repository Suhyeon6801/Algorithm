#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 310;
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
int l;
bool visit[MAX][MAX] = { 0, };
int px, py;
queue<pair<int, int>>que;
int dist = 0;

void bfs(int y, int x)
{
	que.push(make_pair(y, x));
	visit[y][x] = true;

	while (!que.empty())
	{
		int size = que.size();

		while (size--)
		{
			int curY = que.front().first;
			int curX = que.front().second;
			que.pop();

			//cout << curY << " " << curX << endl;

			if (curY == py && curX == px)
			{
				cout << dist << "\n";
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int ny = curY + dy[i];
				int nx = curX + dx[i];

				if (ny < 0 || nx < 0 || ny >= l || nx >= l)	continue;
				else
				{
					if (!visit[ny][nx])
					{
						que.push(make_pair(ny, nx));
						visit[ny][nx] = true;
					}
				}
			}
		}
		dist++;
	}
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
		dist = 0;
		cin >> l;

		int x, y;
		cin >> y >> x >> py >> px;

		bfs(y, x);
		while (!que.empty())
		{
			que.pop();
		}
	}
	
	return 0;
}