#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int par[200010];
vector <pair<int, pair<int, int>>> v;

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

	par[pb] = pa;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n, x, y, z;
	while (1)
	{
		memset(par, 0, sizeof(par));
		v.clear();

		cin >> m >> n;
		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < m; i++)
			par[i] = i;

		int result = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> z;
			v.push_back({ z,{x,y} });
			result += z;
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		int cost = 0;
		for (int i = 0; i < v.size(); i++)
		{
			int a = v[i].second.first;
			int b = v[i].second.second;
			if (find(a) != find(b))
			{
				merge(a, b);
				cost += v[i].first;
				cnt++;

				if (cnt == m - 1)
					break;
			}
		}

		cout << result-cost << "\n";
	}


	return 0;
}