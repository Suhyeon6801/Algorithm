#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct BabyShark {
	int y, x, size, cnt, time;
};

struct Fish {
	int y, x, dist;
};

Fish make_node(int a, int b, int c)
{
	Fish temp;
	temp.y = a;
	temp.x = b;
	temp.dist = c;
	return temp;
}

int N;
int map[30][30];
bool visit[30][30];
BabyShark shark;
vector<Fish> v;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool comp(Fish f1, Fish f2)
{
	if (f1.dist < f2.dist)
		return true;
	else if (f1.dist == f2.dist)
	{
		if (f1.y < f2.y)
			return true;
		else if (f1.y == f2.y)
			return f1.x < f2.x;
		else
			return false;
	}
	else
		return false;

}

void bfs(int y, int x)
{
	queue<Fish> que;
	visit[y][x] = true;
	que.push(make_node(y, x, 0));

	while (!que.empty())
	{
		int curY = que.front().y;
		int curX = que.front().x;
		int curDist = que.front().dist;
		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;

			if (!visit[ny][nx])
			{
				if (map[ny][nx] == 0)
				{
					visit[ny][nx] = true;
					que.push(make_node(ny, nx, curDist + 1));
				}
				else if (map[ny][nx] < shark.size)//먹기 가능 & 이동가능
				{
					visit[ny][nx] = true;
					v.push_back(make_node(ny, nx, curDist + 1));
					que.push(make_node(ny, nx, curDist + 1));
				}
				else if (map[ny][nx] == shark.size)//이동만 가능
				{
					visit[ny][nx] = true;
					que.push(make_node(ny, nx, curDist + 1));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 9)
			{
				shark.y = i;
				shark.x = j;
				shark.size = 2;
				shark.cnt = 0;
				shark.time = 0;
			}
		}
	}

	while (1)
	{
		v.clear();
		memset(visit, 0, sizeof(visit));
		bfs(shark.y, shark.x);

		if (v.size() == 0)
		{
			cout << shark.time << "\n";
			break;
		}
		else if (v.size() == 1)
		{
			map[v[0].y][v[0].x] = 9;
			map[shark.y][shark.x] = 0;
			shark.y = v[0].y, shark.x = v[0].x;
			shark.cnt += 1;
			shark.time += v[0].dist;

			if (shark.size == shark.cnt)//자신의크기와 같은 수의 물고기 먹음.
			{
				shark.size += 1;//사이즈 1증가시켜주고
				shark.cnt = 0;//현재 까지 먹은건 초기화
			}
		}
		else
		{
			sort(v.begin(), v.end(), comp);
			map[v[0].y][v[0].x] = 9;
			map[shark.y][shark.x] = 0;
			shark.y = v[0].y, shark.x = v[0].x;
			shark.cnt += 1;
			shark.time += v[0].dist;

			if (shark.size == shark.cnt)//자신의크기와 같은 수의 물고기 먹음.
			{
				shark.size += 1;//사이즈 1증가시켜주고
				shark.cnt = 0;//현재 까지 먹은건 초기화
			}
		}
	}

	return 0;
}