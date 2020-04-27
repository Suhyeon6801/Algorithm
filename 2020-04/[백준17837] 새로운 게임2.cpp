#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 20;
int N, K;
int map[MAX][MAX];
int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };

struct Chess {
	int y, x, dir;
};

vector<int> chess[MAX][MAX];
vector<Chess> Info;

int ChangeDir(int d)
{
	if (d == 1)	return 2;
	else if (d == 2)	return 1;
	else if (d == 3)	return 4;
	else if (d == 4)	return 3;
}

bool isBoundary(int y, int x)
{
	if (y >= 0 && x >= 0 && y < N&&x < N)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < K; i++)
	{
		int y, x, d;
		cin >> y >> x >> d;
		y--, x--;
		Info.push_back({ y,x,d });
		chess[y][x].push_back(i);
	}

	while (1)
	{
		if (result > 1000)
		{
			cout << "-1\n";
			return 0;
		}

		result++;
		for (int i = 0; i < K; i++)
		{
			int y = Info[i].y;
			int x = Info[i].x;
			//int d = Info[i].dir;

			int ny = y + dy[Info[i].dir];
			int nx = x + dx[Info[i].dir];

			if (!isBoundary(ny, nx) || map[ny][nx] == 2)
			{
				Info[i].dir = ChangeDir(Info[i].dir);

				ny = y + dy[Info[i].dir];
				nx = x + dx[Info[i].dir];
			}

			if (!isBoundary(ny, nx) || map[ny][nx] == 2)	continue;
			else if (map[ny][nx] == 0)
			{
				int idx = -1;
				for (int j = 0; j < chess[y][x].size(); j++)
				{
					int temp = chess[y][x][j];
					//옮길 i가 일치할때 옮기기!!
					if (temp == i)
					{
						idx = j;
					}

					if (idx == -1)	continue;

					Info[temp].y = ny;
					Info[temp].x = nx;
					chess[ny][nx].push_back(temp);

					if (chess[ny][nx].size() >= 4)
					{
						cout << result << "\n";
						return 0;
					}
				}

				int size = chess[y][x].size();
				for (int j = idx; j < size; j++)
					chess[y][x].pop_back();
			}
			else
			{
				int idx = -1;

				for (int j = chess[y][x].size() - 1; j >= 0; j--)
				{
					int temp = chess[y][x][j];
					if (temp == i)
					{
						idx = j;
						break;
					}
				}

				for (int j = chess[y][x].size() - 1; j >= idx; j--)
				{
					int temp = chess[y][x][j];
					Info[temp].y = ny;
					Info[temp].x = nx;
					chess[ny][nx].push_back(temp);

					if (chess[ny][nx].size() >= 4)
					{
						cout << result << "\n";
						return 0;
					}
				}

				int size = chess[y][x].size();
				for (int j = idx; j < size; j++)
					chess[y][x].pop_back();
			}
		}

	}

	return 0;
}