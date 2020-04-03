#include <iostream>
using namespace std;

int map[110][110] = { 0, };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	int y = 0;
	int x = 0;
	int num = 1;
	int dir = 0, cnt = 0;

	while (num <= M * N)
	{
		map[y][x] = num++;

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N || map[ny][nx] != 0)
		{
			dir = (dir + 1) % 4;
			cnt++;
		}

		y += dy[dir];
		x += dx[dir];

	}

	//print(M, N);

	cout << cnt - 1 << "\n";
	
	return 0;
}