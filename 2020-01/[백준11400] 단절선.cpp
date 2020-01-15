#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100010;
vector<int> g[MAX];
int order[MAX];
vector<pair<int, int>> isCut;
int cnt = 1;

int dfs(int x, int parent)
{
	order[x] = cnt;
	cnt++;
	int ret = order[x];

	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		
		if (y == parent)
			continue;
		
		if (order[y])
		{
			ret = min(ret, order[y]);
			continue;
		}

		int prev = dfs(y, x);
		if (prev > order[x])
			isCut.push_back(make_pair(min(y, x), max(y, x)));
		ret = min(ret, prev);
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B;
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	for (int i = 1; i <= V; i++)
	{
		if (!order[i])
			dfs(i, 0);
	}

	sort(isCut.begin(), isCut.end());

	cout << isCut.size() << "\n";
	for (int i = 0; i < isCut.size(); i++)
		cout << isCut[i].first << " " << isCut[i].second << "\n";


	return 0;
}