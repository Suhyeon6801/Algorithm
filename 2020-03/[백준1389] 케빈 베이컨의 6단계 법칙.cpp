#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 5010;
int N, M;
vector<int> graph[MAX];
int dist[110][110];
bool visit[110];

int bfs(int from, int to)
{
	queue<pair<int,int>> que;
	memset(visit, 0, sizeof(visit));

	que.push(make_pair(from,0));
	visit[from] = true;

	while (!que.empty())
	{
		int cur = que.front().first;
		int step = que.front().second;
		que.pop();

		if (cur == to)
		{
			return dist[from][to] = step;
		}

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];

			if (!visit[next])
			{
				que.push(make_pair(next, step + 1));
				visit[next] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
				dist[i][j] = bfs(i, j);
		}
	}

	int getMin = 987654321;
	int idx;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			sum += dist[i][j];
		}

		if (getMin > sum)
		{
			getMin = sum;
			idx = i;
		}
	}

	cout << idx << "\n";
	
	return 0;
}