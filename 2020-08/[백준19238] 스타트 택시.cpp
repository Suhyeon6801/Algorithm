#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 30;
int N, M, energy;
int taxiY, taxiX;
int map[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool visit[MAX][MAX];
bool check[MAX][MAX];

struct Customer {
	int startY, startX, endY, endX;
};

struct Customer_Info{
	int y, x, dist, num;
};

Customer customers[MAX*MAX];
vector<Customer_Info> info;

bool comp(Customer_Info g1, Customer_Info g2)
{
	if (g1.dist < g2.dist)	return true;
	else if (g1.dist == g2.dist)
	{
		if (g1.y < g2.y)	return true;
		else if (g1.y == g2.y)	return g1.x < g2.x;
		else	return false;
	}
	else	return false;
}

int find_close_customer()//택시의 현위치로 부터 가장 가까운 거리에 있는 손님 찾기
{
	memset(visit, 0, sizeof(visit));
	queue<pair<pair<int, int>, pair<int, int>>> que;
	que.push({ { taxiY, taxiX}, {0, energy} });
	visit[taxiY][taxiX] = true;
	info.clear();

	while (!que.empty())
	{
		int y = que.front().first.first;
		int x = que.front().first.second;
		int cnt = que.front().second.first;
		int useEnergy = que.front().second.second;
		que.pop();

		if (map[y][x] >= 1)	info.push_back({ y,x,cnt,map[y][x] });
		if (useEnergy == 0)	continue;
		
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<1 || nx<1 || ny>N || nx>N || visit[ny][nx] || map[ny][nx] == -1)	continue;

			visit[ny][nx] = true;
			que.push({{ ny,nx }, { cnt + 1, useEnergy - 1 }});
		}
	}

	if (info.size() == 0)	return -1;

	sort(info.begin(), info.end(), comp);

	map[info[0].y][info[0].x] = 0;
	energy -= info[0].dist;
	return info[0].num;
}

bool go(int y1, int x1, int y2, int x2)//손님을 목적지로 데려다 주는 최단거리
{
	memset(check, 0, sizeof(check));
	queue<pair<pair<int, int>, pair<int, int>>> que;//위치(y,x),이동거리, 연료사용
	que.push({ {y1,x1},{0,energy} });
	check[y1][x1] = true;

	while (!que.empty())
	{
		int y = que.front().first.first;
		int x = que.front().first.second;
		int d = que.front().second.first;
		int use = que.front().second.second;
		que.pop();

		if (y == y2 && x == x2)
		{
			energy -= d;
			energy += (d * 2);
			taxiY = y, taxiX = x;
			return true;
		}

		if (use == 0)	return false;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny<1 || nx<1 || ny>N || nx>N || check[ny][nx] || map[ny][nx] == -1)	continue;

			check[ny][nx] = true;
			que.push({ {ny,nx} ,{d + 1, use - 1} });
		}
	}

	return false;
}

int solve()
{
	for (int i = 0; i < M; i++)
	{
		int num = find_close_customer();
		if (num == -1)	return -1;
		else
		{
			if (!go(customers[num].startY, customers[num].startX, customers[num].endY, customers[num].endX))
				return -1;
		}
	}

	return energy;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> energy;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 1)	map[i][j] = -1;
		}
	}
	
	cin >> taxiY >> taxiX;

	for (int i = 1; i <= M; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		customers[i] = { a,b,c,d };
		map[a][b] = i;//손님의 위치
	}

	cout << solve() << "\n";

	return 0;
}