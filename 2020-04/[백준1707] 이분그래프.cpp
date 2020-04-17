#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 200010;
vector<int> graph[MAX];
bool visit[MAX];
int color[MAX];
int K;
int V, E;
bool flag;

void init()
{
	for (int i = 0; i < MAX; i++)
		graph[i].clear();

	memset(visit, 0, sizeof(visit));
	memset(color, 0, sizeof(color));
}

void dfs(int x, int num)
{
	visit[x] = true;
	color[x] = num;

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];

		if (visit[y])
		{
			if (color[y] == color[x])
			{
				flag = false;
				return;
			}
		}
		else
		{
			dfs(y, 3 - num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K;
	cin >> K;
	while (K--)
	{
		init();
		flag = true;
		cin >> V >> E;

		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= V; i++)
		{
			if (!visit[i])
			{
				dfs(i, 1);
			}
		}

		if (flag)	cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}[]