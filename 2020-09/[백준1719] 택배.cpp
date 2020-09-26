#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 987654321;
const int MAX = 210;
int preNode[MAX];//도착 직전에 지나는 노드
int dist[MAX];
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	for (int i = 1; i <= N; i++)//시작
	{
		for (int j = 1; j <= N; j++)
			dist[j] = INF;

		pq.push({ 0,i });
		dist[i] = 0;

		while (!pq.empty())
		{
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();

			if (dist[cur] < cost)	continue;

			for (int k = 0; k < v[cur].size(); k++)
			{
				int next = v[cur][k].first;
				int nextCost = v[cur][k].second + cost;

				if (dist[next] > nextCost)
				{
					dist[next] = nextCost;
					preNode[next] = cur;
					pq.push({ nextCost, next });
				}
			}
		}

		for (int j = 1; j <= N; j++)
		{
			if (i == j)//시작점
				cout << "- ";
			else if (preNode[j] == i)//이전이 바로 시작점
				cout << j << " ";
			else//추적
			{
				int curNode = j;
				while (1)
				{
					if (preNode[curNode] == i)
					{
						cout << curNode << " ";
						break;
					}
					else
						curNode = preNode[curNode];
				}
			}
		}

		cout << "\n";
	}

	return 0;
}