#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100010;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int result = 0;
int node = 0;

void dfs(int cur, int cost) {
	visited[cur] = true;

	if (result < cost) {
		result = cost;
		node = cur;
	}

	for (int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i].first;
		int nextCost = tree[cur][i].second;
		if (!visited[next]) {
			dfs(next, cost + nextCost);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V;
	cin >> V;

	int from, to, cost;
	for (int i = 0; i < V; i++) {
		cin >> from;
		while (cin >> to) {
			if (to == -1)	break;
			cin >> cost;

			tree[from].push_back({ to, cost });
		}
	}

	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(node, 0);//해당 노드에서 한 번더!

	cout << result << "\n";

	return 0;
}