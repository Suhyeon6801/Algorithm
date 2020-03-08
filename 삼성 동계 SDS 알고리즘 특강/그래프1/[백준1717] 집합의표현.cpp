#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1000001;
int p[MAX];

int Unionfind(int x)
{
	if (p[x] < 0)
		return x;
	else
	{
		return p[x] = Unionfind(p[x]);
	}
}

bool merge(int a, int b)
{
	a = Unionfind(a);
	b = Unionfind(b);
	if (a == b)	return false;// ¾ÈÇÕÃÄµµ µÊ.

	if (p[a] < p[b])
	{
		p[a] += p[b];
		p[b] = a;
	}
	else
	{
		p[b] += p[a];
		p[a] = b;
	}
	return true;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < MAX; i++)
		p[i] = -1;

	int n, m, cmd, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			merge(a, b);
		}
		else if (cmd == 1)
		{
			if (Unionfind(a) == Unionfind(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}