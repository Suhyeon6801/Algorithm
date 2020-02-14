//DP+DFS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000010;
vector <int> graph[MAX];
vector <int> unidirect[MAX];
bool visit[MAX];
int N;
int dp[MAX][2];//n번이 얼리어답터인지 아닌지.

void dfs(int x)//단방향 그래프로
{
	visit[x] = true;

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visit[y])
		{
			unidirect[x].push_back(y);
			dfs(y);
		}
	}
}

int solve(int node, bool flag)
{
	int& ret = dp[node][flag];
	if (ret != -1)	return ret;

	if (flag)//얼리어답터이면 자식은 얼리어업터여도 되고 아니여도 됨.
	{
		ret = 1;//이미 얼리어덥터
		for (int i = 0; i < unidirect[node].size(); i++)
		{
			int next = unidirect[node][i];
			ret += min(solve(next, true), solve(next, false));
		}
	}
	else//얼리어덥터가 아니면 자식은 무조건 얼리어덥터여야함.
	{
		ret = 0;
		for (int i = 0; i < unidirect[node].size(); i++)
		{
			int next = unidirect[node][i];
			ret += solve(next, true);
		}

	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int u, v;
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);
	memset(dp, -1, sizeof(dp));
	cout << min(solve(1, true), solve(1, false)) << "\n";

	return 0;
}