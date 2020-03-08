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
vector<pair<int, int>> graph[20001];//������, ���α���
bool visit[MAX][MAX];

vector<int> dijkstra(vector<pair<int, int>> trace[MAX], int s, int vertex, int edge)
{
	vector<int> dist(vertex, INF);//dist�ʱ�ȭ
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;//�Ÿ��� ��ȣ�� �ٲ㼭 �Ÿ��� ���� �������� ��������.
		int cur = pq.top().second;

		pq.pop();

		if (dist[cur] < cost)	continue;//���� ���� ��κ��� �� ª�� ��ΰ� �ִٸ� ����

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int d = graph[cur][i].second + cost;

			if (graph[cur][i].second == -1)//���� �ִٰŸ��� ã�� ���� ������ ���� ���� ������ ����.
				continue;

			if (dist[next] > d)//�� ª�� ��� ����
			{
				dist[next] = d;
				pq.push(make_pair(-d, next));//�Ÿ� ��ȣ�� �ٲ㼭 �Ÿ��� ���� �������� �������� �Ѵ�.

											 //trace  ����
				trace[next].clear();
				trace[next].push_back(make_pair(cur, d));
			}
			else if (dist[next] == d)//�ִܰŸ� ã�� �� ���� trace ����
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

		//���ͽ�Ʈ��� �ִܰŸ��� �ش��ϴ� ������ ��´�.
		vector<pair<int, int>> trace[MAX];
		memset(trace, 0, sizeof(trace));
		dijkstra(trace, s, n, m);

		//�ִܰŸ��� �ش�Ǵ� ������ ����� - bfs
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

				//���� ������ ����(graph) 1->2�̸� trace������ ������ 2->1
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