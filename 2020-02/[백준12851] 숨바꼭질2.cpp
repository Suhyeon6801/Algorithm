//BFS(최단경로)+DP(방법의 수)
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
int N, K;
queue<int> que;
bool visit[MAX];
int dist[MAX];//i번째로 오는 최단경로.
int dp[MAX];//i번째로 온 최소방법 수.

void bfs()
{
	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next < 0 || next >= MAX)	continue;

			if (!visit[next])
			{
				que.push(next);
				visit[next] = true;
				dist[next] = dist[cur] + 1;
				dp[next] = dp[cur];
			}
			else if (dist[next] == dist[cur] + 1)
			{
				dp[next] += dp[cur];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	que.push(N);
	visit[N] = true;
	dist[N] = 1;
	dp[N] = 1;

	bfs();

	cout << dist[K] - 1 << "\n";
	cout << dp[K] << "\n";

	return 0;
}