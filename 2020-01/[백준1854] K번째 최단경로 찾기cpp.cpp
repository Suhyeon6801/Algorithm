#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX = 1010;
vector<pair<int, int>> graph[MAX];
priority_queue<int> dist[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	int a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(c, b));
	}

	priority_queue<int, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));//��ߵ��� 1
	dist[1].push(0);

	//���ͽ�Ʈ�� ����
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].second;
			int di = graph[cur][i].first;

			if (dist[next].size() < k)//next�� �ִܰŸ� ������ k���� ���� ��� ��� �߰�
			{
				dist[next].push(di + cost);
				pq.push(make_pair(di + cost, next));
			}
			else if (dist[next].top() > di + cost)//�ִܰŸ� ����
			{
				dist[next].pop();//���ְ�
				dist[next].push(di + cost);//����
				pq.push(make_pair(di + cost, next));
			}

		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i].size() == k)
			cout << dist[i].top() << "\n";
		else
			cout << "-1\n";
	}


	return 0;
}