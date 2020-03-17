#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[5][5];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int stu[25] = { 0, };
bool visit[5][5] = { 0, };
bool isVisit[5][5] = { 0, };
int ans = 0;

bool isAdj()
{
	memset(visit, 0, sizeof(visit));
	memset(isVisit, 0, sizeof(isVisit));
	queue<pair<int, int>> que;

	int temp = 0;
	for (int i = 0; i < 25; i++)
	{
		if (stu[i] == 1)
		{
			int y = i / 5;
			int x = i % 5;

			visit[y][x] = true;

			if (temp == 0)//시작
			{
				que.push(make_pair(y, x));
				isVisit[y][x] = true;
				temp++;
			}
		}
	}

	int flag = 1;
	bool isOk = false;
	while (!que.empty())
	{
		int curY = que.front().first;
		int curX = que.front().second;
		que.pop();

		if (flag == 7)//7곳 모두 인접했음.
		{
			isOk = true;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = curY + dy[i];
			int nx = curX + dx[i];

			if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)	continue;		
			else//stu된곳, 근데 아직 방문은 안함.
			{
				if (visit[ny][nx]==true && isVisit[ny][nx]==false)
				{
					que.push(make_pair(ny, nx));
					isVisit[ny][nx] = true;
					flag++;
				}
			}
			
		}
	}

	if (isOk)	return true;
	else
		return false;
}

bool isFour()
{
	int cnt = 0;

	for (int i = 0; i < 25; i++)
	{
		if (stu[i] == 1)
		{
			int y = i / 5;
			int x = i % 5;

			if (map[y][x] == 'S')	cnt++;
		}
	}

	if (cnt >= 4)	return true;
	else
		return false;
}

void f(int cnt, int idx)
{
	if (cnt == 7)
	{
		if (!isFour() || !isAdj())	return;
		ans++;
		return;
	}

	for (int i = idx; i < 25; i++)
	{
		if (stu[i] == 0)
		{
			stu[i] = 1;
			f(cnt + 1, i);
			stu[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}

	f(0, 0);

	cout << ans << "\n";

	return 0;
}