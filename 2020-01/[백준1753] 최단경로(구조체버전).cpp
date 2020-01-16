#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1000001;

struct Info
{
	int node;//�湮�� ���
	int cost;//�湮�� �������� �Ÿ�
			 /*Info(int n, int c) {->make_node�� �������.
			 node = n;
			 cost = c;
			 }*/
	bool operator < (const Info a)const {//c++���� priority queue�� max�� �۵���.
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
	for (int i = 1; i <= V; i++)//�ʱ�ȭ
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
	pq.push(make_node(S, 0));//�������� �� �߰�
	dist[S] = 0;

	while (!pq.empty())
	{
		//�湮 �ߴ� ���� �� ���� ����� ���� ������ �����´�. -> �ִ� �Ÿ��� Ȯ���� ����
		Info info = pq.top();
		pq.pop();

		int node = info.node;
		int cost = info.cost;

		if (dist[node] != cost)	continue;

		for (Info next : path[node])
		{
			//�ִܰŸ��� Ȯ���� �������� ����Ǵ� ���ο� ����
			//Ȥ�� ���� �Ÿ����� �� ������ �� �� �ִ� ���� �߰��Ѵ�.
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