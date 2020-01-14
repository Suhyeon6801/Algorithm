<<<<<<< HEAD
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

const int MAX = 20010;
const int INF = 10000000;
vector <pair<int, int>> graph[MAX];//������, ����ġ
int V, E;
int dist[MAX];
bool visit[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int u, v, w;
	int start;
	priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> pq;//�ּ���
	cin >> V >> E >> start;

	fill(dist, dist + MAX, INF);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dist[start] = 0;//�������� 0
	pq.push(make_pair(0, start));//dist[v]. v�� �ִ´�. -> �켱������ v�������
	while (!pq.empty())
	{
		int cur;
		do//cur�� �̹� �湮�� ���̸� ����
		{
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);

		if (!visit[cur])
		{
			visit[cur] = true;

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int next = graph[cur][i].first;
				int d = graph[cur][i].second;

				if (dist[next] > dist[cur] + d)
				{
					dist[next] = dist[cur] + d;
					pq.push(make_pair(dist[next], next));
				}
			}
		}
		else//�湮�� ���� ���ǿ� ����
			break;
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
=======
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

const int MAX = 20010;
const int INF = 10000000;
vector <pair<int, int>> graph[MAX];//������, ����ġ
int V, E;
int dist[MAX];
bool visit[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int u, v, w;
	int start;
	priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> pq;//�ּ���
	cin >> V >> E >> start;

	fill(dist, dist + MAX, INF);

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dist[start] = 0;//�������� 0
	pq.push(make_pair(0, start));//dist[v]. v�� �ִ´�. -> �켱������ v�������
	while (!pq.empty())
	{
		int cur;
		do//cur�� �̹� �湮�� ���̸� ����
		{
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);

		if (!visit[cur])
		{
			visit[cur] = true;

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int next = graph[cur][i].first;
				int d = graph[cur][i].second;

				if (dist[next] > dist[cur] + d)
				{
					dist[next] = dist[cur] + d;
					pq.push(make_pair(dist[next], next));
				}
			}
		}
		else//�湮�� ���� ���ǿ� ����
			break;
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INF)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
>>>>>>> bcd348f629f1b37eb96beb3f64464a9a0fcf7319
}