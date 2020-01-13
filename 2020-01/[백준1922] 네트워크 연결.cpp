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

	// ũ�罺Į ����
	//1. �伱���� ����ġ ������ ������������ �����ϰ� 
	sort(edge, edge + m, comp);
	//�������� �� ������Ʈ�� �ʱ�ȭ
	fill(p, p + n, -1);
	int cnt = 0;
	int result = 0;
	//2. �������� Ž���ϸ鼭 ���� ������ ������ ������Ʈ�� ����Ǿ� ���� ������, ������ �̰� ����.
	for (int i = 0; ; i++)//���ѷ���
	{
		if (merge(edge[i].u, edge[i].v))
		{
			result += edge[i].w;
			cnt++;

			//3. ������ ������ n-1�� �� �������� �̷�� �׷����� MST
			if (cnt == n - 1)	break;
		}
	}
	cout << result << "\n";

	return 0;
}