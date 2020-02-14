#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 10010;
vector <int> village[MAX];
bool visit[MAX];
vector <int> tree[MAX];
int arr[MAX];
int dp[MAX][2];//n번마을, 인접여부
int N;

void dfs(int node)
{
	visit[node] = true;
	for (int i = 0; i < village[node].size(); i++)
	{
		int next = village[node][i];
		if (!visit[next])
		{
			tree[node].push_back(next);
			dfs(next);
		}
	}
}

int solve(int node, bool flag)
{
	int& ret = dp[node][flag];
	if (ret != -1)	return ret;

	if (flag)//인접
	{
		ret = arr[node];
		for (int i = 0; i < tree[node].size(); i++)
		{
			int next = tree[node][i];
			ret += solve(next, false);
		}
	}
	else//인접X
	{
		ret = 0;
		for (int i = 0; i < tree[node].size(); i++)
		{
			int next = tree[node][i];
			ret += max(solve(next, false), solve(next, true));
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i < N; i++)
	{
		cin >> a >> b;
		village[a].push_back(b);
		village[b].push_back(a);
	}

	dfs(1);
	memset(dp, -1, sizeof(dp));
	cout << max(solve(1, false), solve(1, true));
	
	return 0;
}