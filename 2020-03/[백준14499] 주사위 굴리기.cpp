#include <iostream>
using namespace std;

int dx[5] = { 0,0,0,-1,1};
int dy[5] = { 0,1,-1,0,0 };
int map[30][30];
int dice[7];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, x, y, K;
	int cmd;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> cmd;

		int ny = y + dy[cmd];
		int nx = x + dx[cmd];

		if (ny < 0 || nx < 0 || ny >= M|| nx >= N)	continue;

		int arr[7] = { 0, };
		if (cmd == 1)//동
		{
			arr[3] = dice[1];
			arr[1] = dice[4];
			arr[4] = dice[6];
			arr[6] = dice[3];
			arr[2] = dice[2];
			arr[5] = dice[5];
		}
		else if (cmd == 2)//서
		{
			arr[6] = dice[4];
			arr[3] = dice[6];
			arr[1] = dice[3];
			arr[4] = dice[1];
			arr[2] = dice[2];
			arr[5] = dice[5];
		}
		else if (cmd == 3)//북
		{
			arr[2] = dice[1];
			arr[1] = dice[5];
			arr[5] = dice[6];
			arr[6] = dice[2];
			arr[3] = dice[3];
			arr[4] = dice[4];
		}
		else if (cmd == 4)//남
		{
			arr[5] = dice[1];
			arr[6] = dice[5];
			arr[2] = dice[6];
			arr[1] = dice[2];
			arr[3] = dice[3];
			arr[4] = dice[4];
		}

		//이동한 칸에 쓰여있는 수가 0이면, 주사위의 바닥면이 복사
		if (map[nx][ny] == 0)
			map[nx][ny] = arr[6];
		else//칸에 쓰여있는 수가 주사위 바닥면에 복사 후 맵은0
		{
			arr[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << arr[1] << "\n";

		for (int i = 0; i < 7; i++)
			dice[i] = arr[i];

		y = ny;
		x = nx;
	}


	return 0;
}