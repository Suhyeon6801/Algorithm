#include <iostream>
using namespace std;

int p[210];

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return find(p[x]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	p[pb] = pa;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int isConnect, order;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		p[i] = i;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> isConnect;
			if (isConnect == 1)
			{
				if (find(i) != find(j))
					merge(i, j);
			}
		}
	}

	int root;
	bool flag = true;
	for (int i = 0; i < M; i++)
	{
		cin >> order;

		if (i == 0)
			root = find(order);
		else
		{
			if (root != find(order))
			{
				flag = false;
				break;
			}
		}
	}

	if (!flag)
		cout << "NO\n";
	else
		cout << "YES\n";

	return 0;
}