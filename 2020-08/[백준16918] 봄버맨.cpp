#include <iostream>
using namespace std;

const int MAX = 210;
int R, C, N;
char map[MAX][MAX];
int BoomTime[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void installBoom(int time)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '.')
			{
				map[i][j] = 'O';
				BoomTime[i][j] = time + 3;
			}
		}
	}
}

void Boom(int time)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (BoomTime[i][j] == time)
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == '.')	continue;
					map[ny][nx] = '.';
				}
				map[i][j] = '.';
				BoomTime[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'O')
				BoomTime[i][j] = 3;
		}
	}

	int sec = 2;
	while (1)
	{
		if (sec == N + 1)	break;

		if (sec % 2 == 0)	installBoom(sec);
		else	Boom(sec);

		sec++;
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}