#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100010;
int N;
vector<int> tree[MAX];
int par[MAX];
bool visit[MAX];

void dfs(int node)
{
	visit[node] = true;

	for (int i = 0; i < tree[node].size(); i++)
	{
		int nextNode = tree[node][i];
		if (!visit[nextNode])
		{
			par[nextNode] = node;
			dfs(nextNode);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2;
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << par[i] << "\n";


	return 0;
}