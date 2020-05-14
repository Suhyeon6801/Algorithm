#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10010;
int arr[MAX];
int par[MAX];
vector<pair<int, int>> v;

int find(int x)
{
	if (x == par[x])
		return x;
	else
		return par[x] = find(par[x]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	if (arr[pa] > arr[pb])
		par[pa] = pb;
	else
		par[pb] = pa;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, k;
	cin >> N >> M >> k;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++)
		par[i] = i;

	for (int i = 0; i < M; i++)
	{
		int v, w;
		cin >> v >> w;
		merge(v, w);
	}

	int cost = 0;
	for (int i = 1; i <= N; i++)
	{
		if (find(i) != 0)
		{
			cost += arr[find(i)];
			merge(find(i), 0);
		}
	}

	//cout << cost << "\n";

	if (cost <= k)
		cout << cost << "\n";
	else
		cout << "Oh no\n";

	return 0;
}