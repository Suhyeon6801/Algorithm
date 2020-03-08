#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

const int MAX = 510;
const int INF = 987654321;
int n, m;
vector<pair<int, int>> graph[20001];//연결점, 도로길이
bool visit[MAX][MAX];

vector<int> dijkstra(vector<pair<int, int>> trace[MAX], int s, int vertex, int edge)
{
	vector<int> dist(vertex, INF);//dist초기화
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;//거리의 부호를 바꿔서 거리가 작은 정점부터 구해진다.
		int cur = pq.top().second;

		pq.pop();

		if (dist[cur] < cost)	continue;//지금 꺼낸 경로보다 더 짧은 경로가 있다면 무시

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int d = graph[cur][i].second + cost;

			if (graph[cur][i].second == -1)//거의 최다거리를 찾기 이해 삭제된 정점 간의 간선은 무시.
				continue;

			if (dist[next] > d)//더 짧은 경로 갱신
			{
				dist[next] = d;
				pq.push(make_pair(-d, next));//거리 부호를 바꿔서 거리가 작은 정점부터 구해지게 한다.

											 //trace  갱신
				trace[next].clear();
				trace[next].push_back(make_pair(cur, d));
			}
			else if (dist[next] == d)//최단거리 찾을 때 마다 trace 갱신
			{
				trace[next].push_back(make_pair(cur, d));
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		memset(graph, 0, sizeof(graph));
		memset(visit, 0, sizeof(visit));
		int s, d;
		int u, v, p;

		cin >> n >> m;
		if (n == 0 && m == 0)	break;

		cin >> s >> d;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> p;
			graph[u].push_back(make_pair(v, p));
		}

		//다익스트라로 최단거리에 해당하는 정점들 담는다.
		vector<pair<int, int>> trace[MAX];
		memset(trace, 0, sizeof(trace));
		dijkstra(trace, s, n, m);

		//최단거리에 해당되는 정점들 지우기 - bfs
		queue<int> que;

		que.push(d);
		while (!que.empty())
		{
			int cur = que.front();
			que.pop();

			for (int i = 0; i < trace[cur].size(); i++)
			{
				int next = trace[cur][i].first;

				if (visit[cur][next])
					continue;

				//원래 정점간 연결(graph) 1->2이면 trace에서의 연결은 2->1
				for (int j = 0; j < graph[next].size(); j++)
				{
					if (graph[next][j].first == cur)
					{
						graph[next][j].second = -1;
					}
				}

				que.push(next);
			}
		}

		vector<int> result = dijkstra(trace, s, n, m);

		if (result[d] == INF)
			cout << "-1\n";
		else
			cout << result[d] << "\n";


	}

	return 0;
}