#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1000001;

struct Info
{
	int node;//방문한 노드
	int cost;//방문한 노드까지의 거리
			 /*Info(int n, int c) {->make_node로 만들었다.
			 node = n;
			 cost = c;
			 }*/
	bool operator < (const Info a)const {//c++에서 priority queue는 max로 작동함.
		return cost > a.cost;
	}
};

Info make_node(int n, int c)
{
	Info temp;
	temp.node = n;
	temp.cost = c;
	return temp;
}

int V, E;
int dist[20001];
vector<Info> path[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int S;
	int u, v, w;
	cin >> V >> E >> S;
	for (int i = 1; i <= V; i++)//초기화
	{
		path[i].clear();
		dist[i] = INF;
	}

	for (int i = 1; i <= E; i++)
	{
		cin >> u >> v >> w;
		path[u].push_back(make_node(v, w));
	}

	priority_queue<Info> pq;
	pq.push(make_node(S, 0));//시작정보 점 추가
	dist[S] = 0;

	while (!pq.empty())
	{
		//방문 했던 정점 중 가장 가까운 정점 정보를 가져온다. -> 최단 거리가 확보된 정점
		Info info = pq.top();
		pq.pop();

		int node = info.node;
		int cost = info.cost;

		if (dist[node] != cost)	continue;

		for (Info next : path[node])
		{
			//최단거리가 확정된 정점에서 연결되는 새로운 정점
			//혹은 기존 거리보다 더 빠르게 갈 수 있는 점을 추가한다.
			if (dist[next.node] > dist[node] + next.cost)
			{
				dist[next.node] = dist[node] + next.cost;
				pq.push(make_node(next.node, dist[next.node]));
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}