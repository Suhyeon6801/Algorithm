#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1010;
vector<int> graph[MAX];
bool check[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int x)
{
	check[x] = true;

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!check[y])
			dfs(y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int u, v;
	int cnt = 0;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			dfs(i);
			cnt++;
		}
	}

	cout << cnt << endl;
	

	return 0;
}
