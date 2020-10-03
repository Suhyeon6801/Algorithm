#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int TIME_MAX = 1000;
const int MAX = 30;
int N, M, k;
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,-1,1 };

struct Shark{
	int y, x, d;
	bool live;
	vector<int> sharkOrder[5];
};

Shark shark[410];

struct Map {
	vector<int> v;//해당좌표에 존재하는 상어 번호
	int smell_time, smell_idx;
};

Map map[MAX][MAX];

bool check_only_one()//1번 상어만 남았는지 확인
{
	for (int i = 2; i <= M; i++)
		if (shark[i].live)	return false;

	return true;
}

void smell_setting(int curTime)//상어들이 현재 자기 위치에 냄새 뿌림.
{
	for (int i = 1; i <= M; i++)
	{
		if (!shark[i].live)	continue;

		int y = shark[i].y;
		int x = shark[i].x;
		map[y][x].smell_idx = i;
		map[y][x].smell_time = curTime + k;
	}
}

void move_sharks(int t)//상어 움직이기
{
	//먼저 map에 있는 상어들의 정보는 비운다.
	for (int i = 1; i <= M; i++)
	{
		if (!shark[i].live)	continue;
		map[shark[i].y][shark[i].x].v.clear();
	}

	//1. 우선순위 순서대로 상하좌우 움직였을 때, 움직일 수 있는 수 있는 칸이 있은 곳(아무 냄새가 없는 빈곳)
	//2. 1번이 없다면 -> 내 냄새가 있는 칸으로.

	for (int i = 1; i <= M; i++)
	{
		if (!shark[i].live)	continue;

		int y = shark[i].y;
		int x = shark[i].x;
		int d = shark[i].d;
		bool flag = false;
		int self_y=-1, self_x=-1, self_d=-1;//이동 못할 때 내 냄새 있는 곳.

		for (int j = 0; j < shark[i].sharkOrder[d].size(); j++)
		{
			int nd = shark[i].sharkOrder[d][j];
			int ny = y + dy[nd];
			int nx = x + dx[nd];

			//상하좌우 인접한 칸 이동
			if (ny >= 0 && nx >= 0 && ny < N&&nx < N)
			{
				if (map[ny][nx].smell_time <= t)//1
				{
					flag = true;
					map[ny][nx].v.push_back(i);
					shark[i].y = ny;
					shark[i].x = nx;
					shark[i].d = nd;
					break;
				}
				else//2
				{
					if (map[ny][nx].smell_idx == i)
					{
						if (self_y == -1)
						{
							self_y = ny;
							self_x = nx;
							self_d = nd;
						}
					}
				}
			}
		}

		if (!flag)
		{
			map[self_y][self_x].v.push_back(i);
			shark[i].y = self_y;
			shark[i].x = self_x;
			shark[i].d = self_d;
		}

	}
}

void kill_sharks()//좌표에 상어가 2마리 이상 있는지 확인하고 있으면 없애기, idx가 작은거 빼고 없앤다.
{
	for (int i = 1; i <= M; i++)
	{
		if (!shark[i].live)	continue;

		int y = shark[i].y, x = shark[i].x;
		if (map[y][x].v.size() >= 2)
		{
			sort(map[y][x].v.begin(), map[y][x].v.end());
			int num = map[y][x].v[0];
			for (int j = 1; j < map[y][x].v.size(); j++)
			{
				shark[map[y][x].v[j]].live = false;
			}
			map[y][x].v.clear();//비우고
			map[y][x].v.push_back(num);//작은 번호 상어 넣기.
			map[y][x].smell_idx = num;
		}
	}
}

int main()//완전 빡구현;;
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//입력순서 : 1. 격자모습 2. 각 상어의 방향 3. 상어당 4줄씩 방향 우선순위
	int a, d, d1, d2, d3, d4, time = 0;
	cin >> N >> M >> k;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a;

			if (a != 0)
			{
				map[i][j].v.push_back(a);
				shark[a].y = i, shark[a].x = j;
			}

			map[i][j].smell_idx = 0, map[i][j].smell_time = 0;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> d;
		shark[i].d = d;
		shark[i].live = true;
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cin >> d1 >> d2 >> d3 >> d4;
			shark[i].sharkOrder[j].push_back(d1);
			shark[i].sharkOrder[j].push_back(d2);
			shark[i].sharkOrder[j].push_back(d3);
			shark[i].sharkOrder[j].push_back(d4);
		}
	}

	while (time <= TIME_MAX)
	{
		if (check_only_one())
		{
			cout << time << "\n";
			return 0;
		}

		smell_setting(time);
		move_sharks(time);
		kill_sharks();
		time++;
	}

	cout << "-1\n";//시간 초과

	return 0;
}