#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100010;
int par[MAX] = { 0, };
int G, P;

int find(int x)
{
	if (par[x] == x)
		return x;
	else 
		return par[x] = find(par[x]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	par[pa] = pb;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> G >> P;

	for (int i = 1; i <= G; i++)
		par[i] = i;

	int docking;
	int gate, cnt = 0;

	for (int i = 1; i <= P; i++)
	{
		cin >> gate;

		int docking = find(gate);
		if (docking != 0)
		{
			merge(docking, docking - 1);
			cnt++;
		}
		else
			break;
	}

	cout << cnt << "\n";
	
	return 0;
}