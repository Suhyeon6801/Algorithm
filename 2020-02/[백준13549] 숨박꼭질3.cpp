//우선순위 큐를 이용한 BFS
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int MAX = 100001;
//경과시간을 기준으로 우선순위 결정, 짧을 수록 더 높은 우선순위
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visit[MAX];
int N, K;

int bfs()
{
	while (!pq.empty())
	{
		int sec = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cur == K)
		{
			return sec;
		}

		int next1 = cur * 2;
		int next2 = cur + 1;
		int next3 = cur - 1;

		if (next1 < MAX && !visit[next1])
		{
			pq.push(make_pair(sec, next1));
			visit[next1] = true;
		}

		if (next2 < MAX && !visit[next2])
		{
			pq.push(make_pair(sec + 1, next2));
			visit[next2] = true;
		}

		if (next3 >= 0 && !visit[next3])
		{
			pq.push(make_pair(sec + 1, next3));
			visit[next3] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	pq.push(make_pair(0, N));
	visit[N] = true;
	cout << bfs();

	return 0;
}