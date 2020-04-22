#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000010;
int N, M;
int result = 0;
struct Edge {
	int from, to, cost;
};

Edge edge[MAX];

int p[100010];

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return p[x] = find(p[x]);
}

void merge(int x, int y, int z)
{
	int px = find(x);
	int py = find(y);

	if (px == py)
		return;

	p[py] = px;
	result += z;
	N--;
}

bool comp(Edge e1, Edge e2)
{
	return e1.cost < e2.cost;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		p[i] = i;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		edge[i].from = A;
		edge[i].to = B;
		edge[i].cost = C;
	}

	sort(edge, edge + M, comp);

	for (int i = 0; i <M ; i++)
	{
		if (find(edge[i].from) != find(edge[i].to))
		{
			merge(edge[i].from, edge[i].to, edge[i].cost);
			
			if (N == 2)
				break;
		}
	}

	cout << result << "\n";

	return 0;
}