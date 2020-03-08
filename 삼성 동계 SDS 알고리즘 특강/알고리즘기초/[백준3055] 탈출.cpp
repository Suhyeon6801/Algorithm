#include <iostream>
#include <queue>
using namespace std;

const int MAX = 60;
char map[MAX][MAX];
bool visited_water[MAX][MAX];
bool visited_slikar[MAX][MAX];
int check[MAX][MAX];
queue <pair<int, int>> start_water;
queue <pair<int, int>> start_slikar;
queue <pair<int, int>> q_water;
queue <pair<int, int>> q_slikar;
int r, c, endY, endX;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void water_bfs()
{
	while (!start_water.empty())
	{
		int a = start_water.front().first;
		int b = start_water.front().second;
		start_water.pop();

		visited_water[a][b] = true;
		q_water.push(make_pair(a, b));
	}

	int size = q_water.size();
	while (size--)
	{
		int currentY = q_water.front().first;
		int currentX = q_water.front().second;
		q_water.pop();

		for (int i = 0; i<4; i++)
		{
			int ny = currentY + dy[i];
			int nx = currentX + dx[i];

			if (ny<0 || nx<0 || ny >= r || nx >= c || map[ny][nx] == 'X' || map[ny][nx] == 'D')  continue;
			else
			{
				if (!visited_water[ny][nx] && map[ny][nx] == '.')
				{
					visited_water[ny][nx] = true;
					map[ny][nx] = '*';
					q_water.push(make_pair(ny, nx));
				}
			}
		}
	}
}

void slikar_bfs()
{
	while (!start_slikar.empty())
	{
		int a = start_slikar.front().first;
		int b = start_slikar.front().second;
		start_slikar.pop();

		visited_slikar[a][b] = true;
		check[a][b] = 1;
		q_slikar.push(make_pair(a, b));
	}

	int size = q_slikar.size();
	while (size--)
	{
		int currentY = q_slikar.front().first;
		int currentX = q_slikar.front().second;
		q_slikar.pop();

		for (int i = 0; i<4; i++)
		{
			int ny = currentY + dy[i];
			int nx = currentX + dx[i];

			if (ny<0 || nx<0 || ny >= r || nx >= c || map[ny][nx] == 'X' || map[ny][nx] == '*')  continue;
			if (ny == endY&&nx == endX)
			{
				check[ny][nx] = check[currentY][currentX] + 1;
				break;
			}
			else
			{
				if (!visited_slikar[ny][nx] && map[ny][nx] == '.')
				{
					visited_slikar[ny][nx] = true;
					check[ny][nx] = check[currentY][currentX] + 1;
					q_slikar.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int main() {

	cin >> r >> c;

	for (int i = 0; i<r; i++)
	{
		for (int j = 0; j<c; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'D')
			{
				endY = i;
				endX = j;
			}
		}
	}

	for (int i = 0; i<r; i++)
	{
		for (int j = 0; j<c; j++)
		{
			if (map[i][j] == '*')
			{
				start_water.push(make_pair(i, j));
			}

			if (map[i][j] == 'S')
			{
				start_slikar.push(make_pair(i, j));
			}
		}
	}

	water_bfs();
	slikar_bfs();

	while (1)
	{
		if (check[endY][endX] != 0)
		{
			cout << check[endY][endX] - 1 << endl;
			break;
		}
		if (q_slikar.empty())
		{
			if (check[endY][endX] != 0)
			{
				cout << check[endY][endX] - 1 << endl;
				break;
			}
			else
			{
				cout << "KAKTUS" << endl;
				break;
			}
		}

		water_bfs();
		slikar_bfs();
	}

	return 0;
}