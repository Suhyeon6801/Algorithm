#include <iostream>
#include <queue>
using namespace std;

const int MAX = 60;
char map[MAX][MAX];
int check[MAX][MAX];
int r, c;
int ex, ey;
queue<pair<int, int>> water;
queue<pair<int, int>> que;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool waterVisited[MAX][MAX];
bool visited[MAX][MAX];

void waterBFS()
{
	/*while (!water.empty())
	{*/
	int size = water.size();
	while (size--)
	{
		int y = water.front().first;
		int x = water.front().second;
		water.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] == 'D' || map[ny][nx] == 'X')	continue;
			else
			{
				if (!waterVisited[ny][nx])
				{
					map[ny][nx] = '*';
					waterVisited[ny][nx] = true;
					water.push(make_pair(ny, nx));
				}
			}
		}
	}
	//}
}

void BFS()
{
	//while (!que.empty())
	//{
	int size = que.size();
	while (size--)
	{
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		if (y == ey && x == ex)
		{
			//cout << check[y][x] << "\n";
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || map[ny][nx] == '*' || map[ny][nx] == 'X')	continue;
			else
			{
				if (!visited[ny][nx])
				{
					visited[ny][nx] = true;
					que.push(make_pair(ny, nx));
					check[ny][nx] = check[y][x] + 1;
				}
			}
		}
	}
	//}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'D')
			{
				ey = i, ex = j;
			}
			else if (map[i][j] == 'S')
			{
				que.push(make_pair(i, j));
				visited[i][j] = true;
				check[i][j] = 1;
			}
			else if (map[i][j] == '*')
			{
				water.push(make_pair(i, j));
				waterVisited[i][j] = true;
			}
		}
	}

	while (1)
	{
		waterBFS();
		BFS();

		if (check[ey][ex] != 0)
		{
			cout << check[ey][ex] - 1 << "\n";
			break;
		}
		else if (que.empty())
		{
			if (check[ey][ex] == 0)
			{
				cout << "KAKTUS\n";
				break;
			}
			else
			{
				cout << check[ey][ex] - 1 << "\n";
				break;
			}
		}
	}

	return 0;
}