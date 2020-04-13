#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 30;
const int INF = 987654321;
struct Pos {
	int y, x, cnt;
};

Pos make_node(int a, int b, int c)
{
	Pos temp;
	temp.y = a;
	temp.x = b;
	temp.cnt = c;
	return temp;
}

char map[MAX][MAX];
int w, h;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> dirtyRoom;
bool visit[MAX][MAX];
int dist[MAX][MAX];
int ry, rx;
int dirty = 0;
int order[MAX];
bool check[MAX];
int result = INF;

void bfs(int p1, int p2)//서로 간의 최단 거리 찾기
{
	memset(visit, 0, sizeof(visit));
	queue<Pos> que;
	que.push(make_node(dirtyRoom[p1].first, dirtyRoom[p1].second,0));
	visit[dirtyRoom[p1].first][dirtyRoom[p1].second] = true;

	int destY = dirtyRoom[p2].first, destX = dirtyRoom[p2].second;

	while (!que.empty())
	{
		int y = que.front().y;
		int x = que.front().x;
		int cnt = que.front().cnt;
		que.pop();

		if (y == destY && x == destX)
		{
			dist[p1][p2] = cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w || map[ny][nx] == 'x')	continue;

			if (!visit[ny][nx])
			{
				visit[ny][nx] = true;
				que.push(make_node(ny, nx, cnt + 1));
			}
		}
	}

	dist[p1][p2] = -1;
	return;
}


void dfs(int cnt)//순열로 방청소 순서 구하기
{
	if (cnt == dirty)
	{
		int d = dist[dirty][order[0]];

		if (d > -1)
		{
			for (int i = 1; i < dirty; i++)
			{
				int temp = dist[order[i]][order[i-1]];
				if (temp == -1)	return;

				d += temp;
			}

			result = min(d, result);
		}
		
		return;
	}

	for (int i = 0; i < dirty; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			order[cnt] = i;
			dfs(cnt + 1);
			order[cnt] = 0;
			check[i] = false;
		}
	}
}

void init()
{
	memset(map, 0, sizeof(map));
	memset(check, 0, sizeof(check));
	memset(order, 0, sizeof(order));
	memset(dist, 0, sizeof(dist));
	dirtyRoom.clear();
	dirty = 0;
	result = INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)	break;

		init();

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];

				if (map[i][j] == 'o')
				{
					ry = i, rx = j;
				}
				else if (map[i][j] == '*')
				{
					dirtyRoom.push_back(make_pair(i, j));
					dirty++;//더러운 방의 개수
				}
			}
		}

		dirtyRoom.push_back(make_pair(ry, rx));

		for (int i = 0; i < dirtyRoom.size(); i++)
		{
			for (int j = 0; j < dirtyRoom.size(); j++)
			{
				if (i != j)
					bfs(i, j);
			}
		}

		dfs(0);

		if (result >= INF)
			cout << "-1\n";
		else
			cout << result << "\n";
	}

	return 0;
}