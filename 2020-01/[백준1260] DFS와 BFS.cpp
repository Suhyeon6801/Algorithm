#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1010;
vector <int> graph[MAX];
bool visit[MAX] = { 0, };

void dfs(int x)
{
	visit[x] = true;

	cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];

		if (!visit[y])	dfs(y);
	}
}

void bfs(int x)
{
	queue<int> que;

	visit[x] = true;
	que.push(x);

	while (!que.empty())
	{
		int y = que.front();
		que.pop();

		cout << y << " ";

		for (int i = 0; i < graph[y].size(); i++)
		{
			int z = graph[y][i];
			if (!visit[z])
			{
				visit[z] = true;
				que.push(z);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, v;
	int a, b;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << "\n";
	memset(visit, 0, sizeof(visit));
	bfs(v);

	return 0;
}
