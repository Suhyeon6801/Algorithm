#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <functional>
using namespace std;

const int MAX = 20010;
const int INF = 987654321;
int N, M;
vector<int> graph[MAX];
int dist[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	fill(dist+1, dist+1 + N, INF);

	dist[1] = 0;
	pq.push({ 0,1 });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost)	continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			int nextCost = cost + 1;

			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push({ nextCost, next });
			}
		}
	}

	int result = 1;
	int cnt = 0;
	for (int i = 2; i <= N; i++)
	{
		if (dist[result] < dist[i])
		{
			result = i;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (dist[result] == dist[i])
			cnt++;
	}

	cout << result << " " << dist[result] << " " << cnt << "\n";

	return 0;
}