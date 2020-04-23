#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 110;
int R, C, M;
vector<int> map[MAX][MAX];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };
int result = 0;

struct Shark {
	int y, x, size, speed, dir, idx;
};

Shark make_node(int r, int c, int s, int d, int z, int i)
{
	Shark temp;
	temp.y = r;
	temp.x = c;
	temp.speed = s;
	temp.dir = d;
	temp.size = z;
	temp.idx = i;
	return temp;
}

vector<Shark> sharks;

bool isShark()//잡을 상어가 있는지 확인.
{
	for (int i = 0; i < sharks.size(); i++)
	{
		if (sharks[i].size != 0)	return false;
	}

	return true;
}

bool comp(int a, int b)
{
	return sharks[a].size > sharks[b].size;
}

void Fishing(int x)
{
	for (int i = 1; i <= R; i++)
	{
		if (map[i][x].size() != 0)
		{
			int idx = map[i][x][0];
			result += sharks[idx].size;
			sharks[idx].size = 0;//상어 잡힘..
			map[i][x].clear();
			break;
		}
	}
}

void MoveSharks()
{
	for (int i = 0; i < sharks.size(); i++)
	{
		if (sharks[i].size == 0)	continue;

		int y = sharks[i].y;
		int x = sharks[i].x;

		map[y][x].clear();
	}

	for (int i = 0; i < sharks.size(); i++)
	{
		if (sharks[i].size == 0)	continue;

		int y = sharks[i].y;
		int x = sharks[i].x;
		int dir = sharks[i].dir;
		int speed = sharks[i].speed;

		int rotate_point;

		if (dir == 1 || dir == 2)//↑,↓
		{
			rotate_point = (R - 1) * 2;
			if (rotate_point <= speed)
				speed = speed % rotate_point;

			for (int d = 0; d < speed; d++)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (ny > R)
				{
					dir = 1;
					ny = ny - 2;
				}

				if (ny < 1)
				{
					dir = 2;
					ny = ny + 2;
				}

				y = ny;
				x = nx;
			}
		}
		else if (dir == 3 || dir == 4)//->, <-
		{
			rotate_point = (C - 1) * 2;

			if (rotate_point <= speed)
				speed = speed % rotate_point;

			//speed만큼 이동해주기!
			for (int d = 0; d < speed; d++)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];

				if (nx > C)
				{
					dir = 4;
					nx = nx - 2;
				}

				if (nx < 1)
				{
					dir = 3;
					nx = nx + 2;
				}

				y = ny;
				x = nx;
			}
		}
		

		sharks[i].y = y;
		sharks[i].x = x;
		sharks[i].dir = dir;
		map[y][x].push_back(i);

	}

	//한칸에 상어 1마리씩 있는지, 2마리 이상이면 사이즈가 큰 놈이 다 먹는다.
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (map[i][j].size() >= 2)
			{
				sort(map[i][j].begin(), map[i][j].end(), comp);//사이즈 큰 순서로 정렬

				int shark_idx = map[i][j][0];

				for (int k = 1; k < map[i][j].size(); k++)//먹힌 상어는 -1로 표시해주자.
				{
					int idx = map[i][j][k];
					sharks[idx].y = -1;
					sharks[idx].x = -1;
					sharks[idx].size = 0;
				}

				map[i][j].clear();
				map[i][j].push_back(sharks[shark_idx].idx);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c, s, d, z;
	cin >> R >> C >> M;

	if (M == 0)
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i <M; i++)
	{
		cin >> r >> c >> s >> d >> z;

		map[r][c].push_back(i);
		sharks.push_back(make_node(r,c,s,d,z,i));
	}

	for (int i = 1; i <= C; i++)
	{
		if (isShark())	break;
		Fishing(i);
		MoveSharks();

	}

	cout << result << "\n";

	return 0;
}