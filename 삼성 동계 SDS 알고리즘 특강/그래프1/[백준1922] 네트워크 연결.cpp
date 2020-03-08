#include <iostream>
#include <algorithm>
using namespace std;

int p[1000];

struct Edge
{
	int u;
	int v;
	int w;
};

Edge edge[100000];

int find(int x)
{
	if (p[x] < 0)
		return x;
	else
		return p[x] = find(p[x]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return false;

	p[b] = a;
	return true;
}

bool comp(Edge e1, Edge e2)
{
	return e1.w < e2.w;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a, b, c;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		edge[i].u = a - 1;
		edge[i].v = b - 1;
		edge[i].w = c;
	}

	// 크루스칼 구현
	//1. 긴선들의 가중치 순으로 오름차순으로 정렬하고 
	sort(edge, edge + m, comp);
	//정점들을 각 컴포넌트로 초기화
	fill(p, p + n, -1);
	int cnt = 0;
	int result = 0;
	//2. 간선들을 탐색하면서 양쪽 정점을 포함한 컴포턴트가 연결되어 있지 않으면, 간선을 뽑고 연결.
	for (int i = 0; ; i++)//무한루프
	{
		if (merge(edge[i].u, edge[i].v))
		{
			result += edge[i].w;
			cnt++;

			//3. 간선의 개수가 n-1일 때 정점들이 이루는 그래프는 MST
			if (cnt == n - 1)	break;
		}
	}
	cout << result << "\n";

	return 0;
}