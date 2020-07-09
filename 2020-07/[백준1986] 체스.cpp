#include <iostream>
using namespace std;

int N, M;
int chess[1010][1010];
bool check[1010][1010];
int Queen_dy[8] = { 0,1,0,-1,-1,-1,1,1 };
int Queen_dx[8] = { 1,0,-1,0,-1,1,-1,1 };
int Knight_dy[8]= { -1,1,-2,-2,-1,1,2,2 };
int Knight_dx[8]= { -2,-2,-1,1,2,2,-1,1 };

void CheckArea(int y, int x, char c)
{
	if (c == 'Q')
	{
		for (int i = 0; i < 8; i++)
		{
			int ny, nx;
			int yy = y, xx = x;

			while (1)
			{
				ny = yy + Queen_dy[i];;
				nx=xx+ Queen_dx[i];

				if (ny < 1 || nx < 1 || nx > M || ny > N ||chess[ny][nx]!=0)	break;

				check[ny][nx] = true;
				yy = ny;
				xx = nx;;
			}
		}
	}
	else 
	{
		for (int i = 0; i < 8; i++)
		{
			int ny = y + Knight_dy[i];
			int nx = x + Knight_dx[i];

			if (ny >= 1 && nx >= 1 && ny <= N && nx <= M && chess[ny][nx] == 0)
				check[ny][nx] = true;
		}
	}
}

int result()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (chess[i][j] == 0 && !check[i][j])	cnt++;
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int Q, K, P, y, x;
	cin >> N >> M;
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> y >> x;
		chess[y][x] = 1;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> y >> x;
		chess[y][x] = 2;
	}
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		cin >> y >> x;
		chess[y][x] = 3;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (chess[i][j] == 0)	continue;

			if (chess[i][j] == 1)
			{
				check[i][j] = true;
				CheckArea(i, j, 'Q');
			}
			else if (chess[i][j] == 2)
			{
				check[i][j] = true;
				CheckArea(i, j, 'K');
			}
			else if (chess[i][j] == 3)	check[i][j] = true;
		}
	}

	cout << result() << "\n";

	return 0;
}