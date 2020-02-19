#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;
const int MAX = 100010;
const int INF = 987654321;
vector<pair<int, int>> city[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int from, to, cost;
	int startPoint, endPoint;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		city[from].push_back(make_pair(to, cost));
		//city[to].push_back(make_pair(from, cost));
	}

	cin >> startPoint >> endPoint;

	fill(dist, dist + MAX, INF);

	dist[startPoint] = 0;
	pq.push(make_pair(0, startPoint));

	while (!pq.empty())
	{
		int curCost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < curCost)
			continue;

		for (int i = 0; i < city[cur].size(); i++)
		{
			int next = city[cur][i].first;
			int nextCost = city[cur][i].second + curCost;

			if (dist[next] > nextCost)
			{
				dist[next] = nextCost;
				pq.push(make_pair(nextCost, next));
			}
		}
	}

	//for (int i = 1; i <= N; i++)
	//	cout << dist[i] << " ";
	//cout << "\n";

	cout << dist[endPoint] << "\n";

	return 0;
}