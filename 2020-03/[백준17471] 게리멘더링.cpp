#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N;
int Adj[20][20];//구역별 연결여부
int population[20];//인구수
int visit[20];//dfs탐색시 방분여부 확인
bool isSelect[20];//조합 구현시 뽑은 데이터 체크 저장
int getMin = INF;
int result;

bool isConnect(vector<int> v, bool connect)//bfs로 연결여부 확인
{
	memset(visit, 0, sizeof(visit));

	queue<int> que;
	que.push(v[0]);
	visit[v[0]] = true;
	int cnt = 1;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		for (int i = 1; i <= N; i++)
		{
			//현재 구역과 탐색 구역이 연결되어있고
			//탐색하려는 구역이 선거구인지
			//방문여부
			if (Adj[cur][i] == 1 && isSelect[i] == connect && !visit[i])
			{
				que.push(i);
				visit[i] = true;
				cnt++;
			}
		}
	}

	if (cnt == v.size())
		return true;
	else
		return false;
}

bool check()
{
	//구역개수가 1개 이상이고 선거구끼리 연결되어있는지
	vector<int> v1, v2;//선거구 2개
	for (int i = 1; i <= N; i++)
	{
		if (isSelect[i])
			v1.push_back(i);
		else
			v2.push_back(i);
	}

	if (v1.size() == 0 || v2.size() == 0)	return false;

	if (!isConnect(v1, true))//뽑은 구역들
		return false;

	if (!isConnect(v2, false))//안뽑은 구역들
		return false;

	return true;
}
void calc()//차이 계산
{
	int temp1 = 0, temp2 = 0;

	for (int i = 1; i <= N; i++)
	{
		if (isSelect[i])
			temp1 += population[i];
		else
			temp2 += population[i];
	}

	getMin = min(getMin, abs(temp1 - temp2));
}

void f(int idx, int cnt)//선거구 뽑기
{
	if (cnt >= 1)
	{
		if (check())
			calc();

		//return;->없어야 댐! 최소 1개 이상을 뽑으니까 1개 이상 뽑으면 무조거 계산!
	}

	for (int i = idx; i <= N; i++)
	{
		if (!isSelect[i])
		{
			isSelect[i] = true;
			f(i, cnt + 1);
			isSelect[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> population[i];

	for (int i = 1; i <= N; i++)
	{
		int m, p;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> p;
			Adj[i][p] = 1;
			Adj[p][i] = 1;
		}
	}

	//선거구 뽑기 -> 조합(뽑은것들 모아서 선거구1, 안뽑은것들 모아서 선거구2)
	f(1, 0);

	if (getMin == INF)
		cout << "-1\n";
	else
		cout << getMin << "\n";

	return 0;
}