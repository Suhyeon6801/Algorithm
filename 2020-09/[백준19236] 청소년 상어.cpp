#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int map[4][4];
int dy[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int answer = -1;
struct Fish {
	int y, x, dir;
	bool isLive;
};
Fish fish[20];

void change_loc(int a, int b)//물고기끼리 위치 바꾸기
{
	Fish temp = fish[a];
	fish[a].y = fish[b].y;
	fish[a].x = fish[b].x;
	fish[b].y = temp.y;
	fish[b].x = temp.x;
}

void move_fish()//물고기 이동
{
	for (int i = 1; i <= 16; i++)
	{
		if (fish[i].isLive)
		{
			int y = fish[i].y;
			int x = fish[i].x;
			int d = fish[i].dir;

			int ny = y + dy[d];
			int nx = x + dx[d];
			bool isRotate = true;//현위치에서 45도 회전할지 확인

			if (ny >= 0 && nx >= 0 && nx < 4 && ny < 4)
			{
				if (map[ny][nx] == 0)//바꿀 위치에 물고기가 없음 -> 걍 그 위치로 이동
				{
					isRotate = false;
					fish[i].y = ny;
					fish[i].x = nx;
					map[ny][nx] = i;
					map[y][x] = 0;
				}
				else if (map[ny][nx] != -1)//바꿀 위치에 물고기가 있음 -> 그 위치 물고기랑 자리 이동
				{
					isRotate = false;
					change_loc(i, map[ny][nx]);
					swap(map[y][x], map[ny][nx]);
				}
			}

			if (isRotate)//현위치에서 해당 방향으로 움직일 수 없다! -> 45도씩 기울이며 방향 탐색
			{
				int nd = d + 1;
				if (nd == 9)	nd = 1;

				int nny = y + dy[nd];
				int nnx = x + dx[nd];

				while (nd != d)
				{
					if (nny >= 0 && nnx >= 0 && nnx < 4 && nny < 4)
					{
						if (map[nny][nnx] == 0)
						{
							fish[i].y = nny;
							fish[i].x = nnx;
							fish[i].dir = nd;
							map[nny][nnx] = i;
							map[y][x] = 0;
							break;
						}
						else if (map[nny][nnx] != -1)
						{
							change_loc(i, map[nny][nnx]);
							swap(map[y][x], map[nny][nnx]);
							fish[i].dir = nd;
							break;
						}
					}

					nd++;
					if (nd == 9)	nd = 1;
					nny = y + dy[nd];
					nnx = x + dx[nd];
				}
			}
		}
	}
}

void shark_move(int sy, int sx, int fy, int fx, int fnum, bool ate)
{
	if (ate)//fy,fx에 있는 물고기 먹혔다->상어 표기
	{
		map[sy][sx] = 0;
		map[fy][fx] = -1;
		fish[fnum].isLive = false;
	}
	else
	{
		map[sy][sx] = -1;
		map[fy][fx] = fnum;
		fish[fnum].isLive = true;
	}
}

void copyState(int a[4][4], int b[4][4], Fish f1[20], Fish f2[20])
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			a[i][j] = b[i][j];

	for (int i = 1; i <= 16; i++)
		f1[i] = f2[i];
}

void dfs(int y, int x, int d, int sum)//백트래킹으로 먹을 물고기 선택하기
{
	answer = max(answer, sum);

	//맵 복사 + 물고기 정보 복사
	int arr[4][4];
	Fish temp[20];
	copyState(arr, map, temp, fish);

	move_fish();//물고기 움직이기

	for (int i = 1; i <= 3; i++)//상어 움직이기
	{
		int ny = y + dy[d] * i;
		int nx = x + dx[d] * i;

		if (ny >= 0 && nx >= 0 && nx < 4 && ny < 4)
		{
			if (map[ny][nx] == 0)	continue;

			int fish_num = map[ny][nx];
			int fish_dir = fish[fish_num].dir;

			shark_move(y, x, ny, nx, fish_num, true);//(y,x)에 있는 상어가 (ny,nx)에 있는 상어를 먹었다.
			dfs(ny, nx, fish_dir, sum + fish_num);
			shark_move(y, x, ny, nx, fish_num, false);//초기화
		}
		else	break;
	}

	//원위치
	copyState(map, arr, fish, temp);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a >> b;
			map[i][j] = a;
			fish[a] = { i,j,b,true };
		}
	}

	int sharkD = fish[map[0][0]].dir;
	int sum = map[0][0];
	fish[map[0][0]].isLive = false;
	map[0][0] = -1;//여기에 상어 있다!!

	dfs(0, 0, sharkD, sum);

	cout << answer << "\n";

	return 0;
}