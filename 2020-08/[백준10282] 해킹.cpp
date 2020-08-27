#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

const int MAX = 100010;
const int INF = 987654321;
vector<pair<int, int>> graph[MAX];
int dist[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int n, d, c;
		cin >> n >> d >> c;

		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}

		for (int i = 1; i <= n; i++)
			dist[i] = INF;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair(0,c));
		dist[c] = 0;

		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();

			if (dist[cur] < cost)	continue;

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int next = graph[cur][i].first;
				int nextCost = graph[cur][i].second + cost;
				

				if (dist[next] > nextCost)
				{
					dist[next] = nextCost;
					pq.push(make_pair(nextCost, next));
				}

			}
		}

		int cnt = 0, result = -1;
		for (int i = 1; i <= n; i++)
		{
			if (dist[i] == INF)	continue;
			cnt++;
			result = max(result, dist[i]);
		}
			
		cout << cnt << " " << result << "\n";

        //초기화
		for (int i = 0; i < d; i++)
			graph[i].clear();
		memset(dist, 0, sizeof(dist));
	}

	return 0;
}