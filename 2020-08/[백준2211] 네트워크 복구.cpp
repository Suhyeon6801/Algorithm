#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 987654321;
vector<pair<int, int>> graph[1010];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[1010];
int par[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	//MST + dijkstra
	int N, M, A, B, C;
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		graph[A].push_back({ B,C });
		graph[B].push_back({ A,C });
	}

	for (int i = 1; i <= N; i++)
		dist[i] = INF;

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
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second + cost;

			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push({ nextCost, next });
				par[next] = cur;
			}
		}
	}

	cout << N - 1 << "\n";
	for (int i = 2; i <= N; i++)
		cout << par[i] << " " << i << "\n";

	return 0;
}