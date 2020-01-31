#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
	int from, to;
	long long cost;
};
Edge edge[100010];
int p[10010];

int find(int x)
{
	if (x==p[x])	return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	p[pb] = pa;
}

bool comp(Edge e1, Edge e2)
{
	return e1.cost < e2.cost;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		p[i] = i;

	for (int i = 0; i < E; i++)
	{
		cin >> edge[i].from >> edge[i].to >> edge[i].cost;
	}

	sort(edge, edge + E, comp);

	/*cout << "출력\n";
	for (int i = 0; i < E; i++)
		cout << edge[i].from << " " << edge[i].to << " " << edge[i].cost << "\n";*/

	int cnt = 0;
	long long ans = 0;
	for(int i=0; i<E; i++)
	{
		if (find(edge[i].from) != find(edge[i].to))
		{
			merge(edge[i].from, edge[i].to);
			ans += edge[i].cost;
			cnt++;

			if (cnt == V - 1)	break;
		}
	}

	cout << ans;

	return 0;
}