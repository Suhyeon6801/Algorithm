#include <iostream>
using namespace std;

int N;
int arr[20][20];
int dy[3] = { 0,1,1 };
int dx[3] = { 1,0,1 };//0가로,1세로, 2 대각선
int result = 0;

void f(int y, int x, int pipe)
{
	if (y == N && x == N)
	{
		result++;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 && pipe == 1) || (i == 1 && pipe == 0))	continue;

		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny<1 || nx<1 || ny>N || nx>N || arr[ny][nx] == 1)	continue;
		if (i == 2 && (arr[y + 1][x] == 1 || arr[y][x + 1] == 1))	continue;

		f(ny, nx, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	f(1, 2, 0);//처음에 가로로 시작

	cout << result << "\n";

	return 0;
}