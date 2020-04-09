#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

struct Enemy_info {
	int y, x, d;
};

Enemy_info make_node(int a, int b, int c)
{
	Enemy_info temp;
	temp.y = a;
	temp.x = b;
	temp.d = c;

	return temp;
}

int map[20][20];
int arr[20][20];//맵 복사
bool visit[20][20];
bool isSelect[20];
int N, M, D;
vector<int> archer;
vector<pair<int, int>> enemy;
int getMax = -1;
int ans;

int getDist(int r1, int c1, int r2, int c2)
{
	return abs(r1 - r2) + abs(c1 - c2);
}

bool comp(Enemy_info e1, Enemy_info e2)
{
	if (e1.d < e2.d)//가까운 적 순
		return true;
	else if (e1.d == e2.d)//같은 위치에 적이 있다면
	{
		return e1.x < e2.x;//왼쪽에 있는거 먼저
	}
	else
		return false;
}

void copyMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = map[i][j];
		}
	}
}

bool all_kill()//적이 모두 죽었는지
{
	bool flag = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				flag = false;
				enemy.push_back(make_pair(i, j));
			}
		}
	}

	if (flag)
		return true;
	else
		return false;
}

void move_enemy()
{
	//아래에서 위로 해줘야함.
	//위에서 해주면 엉켜버림.
	for (int i = enemy.size()-1; i >=0; i--)
	{
		int y = enemy[i].first;
		int x = enemy[i].second;

		if (arr[y][x] == 0)	continue;

		if (y == N - 1)
			arr[y][x] = 0;
		else
		{
			arr[y][x] = 0;
			arr[y + 1][x] = 1;//아래로 한칸 이동
		}

	}
}

void shot()
{
	pair<int, int> arrow[3];//궁수별 화살 날리기

	for (int i = 0; i < archer.size(); i++)
	{
		int y = N;
		int x = archer[i];

		vector<Enemy_info> info;

		for (int j = 0; j < enemy.size(); j++)
		{
			int ey = enemy[j].first;
			int ex = enemy[j].second;

			int dist = getDist(y, x, ey, ex);
			if (dist <= D)
			{
				info.push_back(make_node(ey, ex, dist));
			}
		}

		int kill_cnt = info.size();//죽일 적의 개수
		if (kill_cnt == 1)//적이 하나인 경우
		{
			arrow[i].first = info[0].y;
			arrow[i].second = info[0].x;
		}
		else if (kill_cnt > 1)//적이 여러개 -> 가장 왼쪽에 있는 적 공격
		{
			sort(info.begin(), info.end(), comp);
			arrow[i].first = info[0].y;
			arrow[i].second = info[0].x;
		}
		else//죽일 적 없다.
		{
			arrow[i].first = -1;
			arrow[i].second = -1;
		}
	}

	for (int i = 0; i < 3; i++)//각 궁수별 죽일 적.
	{
		int y = arrow[i].first;
		int x = arrow[i].second;

		if (y == -1 && x == -1)	continue;
		if (!visit[y][x])
		{
			visit[y][x] = true;
			arr[y][x] = 0;//kill
			ans++;
		}
	}
}

void attack()
{
	copyMap();

	while (1)
	{
		enemy.clear();
		memset(visit, 0, sizeof(visit));

		if (all_kill())
			break;

		shot();//궁수 공격
		move_enemy();//적 이동
	}
}

void f(int cnt, int idx)//궁수를 배치(조합)
{
	if (cnt == 3)
	{
		ans = 0;
		attack();
		getMax = max(getMax, ans);
		return;
	}

	for (int i = idx; i < M; i++)
	{
		if (!isSelect[i])
		{
			isSelect[i] = true;
			archer.push_back(i);
			f(cnt + 1, i);
			archer.pop_back();
			isSelect[i] = false;
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	f(0,0);

	cout << getMax << "\n";
	
	return 0;
}