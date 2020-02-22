#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Pos {
	int x, y;
};

Pos p[110];
bool visit[110];
int n;
bool happy;

int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(int x, int y)
{
	if (x == p[n + 1].x&&y == p[n + 1].y)
	{
		happy = true;
		return;
	}

	for (int i = 1; i < n + 2; i++)
	{
		if (!visit[i] && dist(x, y, p[i].x, p[i].y)<=1000)
		{
			visit[i] = true;
			dfs(p[i].x, p[i].y);
			//visit[i] = false;
		}
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		happy = false;
		memset(visit, 0, sizeof(visit));
		memset(p, 0, sizeof(p));
		cin >> n;
		for (int i = 0; i < n + 2; i++)
			cin >> p[i].x >> p[i].y;

		visit[0] = true;
		dfs(p[0].x, p[0].y);

		if (happy)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	
	return 0;
}