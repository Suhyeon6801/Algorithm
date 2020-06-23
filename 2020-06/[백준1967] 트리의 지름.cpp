#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 10010;
int N;
vector<pair<int, int>> Node[MAX];
bool visit[MAX];
int ans = 0, end_Node;

void dfs(int cur, int level)
{
	visit[cur] = true;

	if (ans < level)
	{
		ans = level;
		end_Node = cur;
	}

	for (int i = 0; i < Node[cur].size(); i++)
	{
		int next = Node[cur][i].first;
		if(!visit[next])
			dfs(next, Node[cur][i].second + level);
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int root, node, weight;
	cin >> N;

	for (int i = 0; i < N -1; i++)
	{
		cin >> root >> node >> weight;
		Node[root].push_back({ node, weight });
		Node[node].push_back({ root, weight });
	}

	dfs(1, 0);

	ans = 0;
	memset(visit, 0, sizeof(visit));

	dfs(end_Node, 0);

	cout << ans << "\n";
	

	return 0;
}