#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[60];
bool visit[60];

int bfs(int x)
{
	int leaf = 0;
	queue<int> que;
	que.push(x);
	visit[x] = true;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		int child = 0;//현재 노드의 자식수
		for (int i = 0; i < tree[cur].size(); i++)
		{
			int next = tree[cur][i];
			if (!visit[next])
			{
				child++;
				visit[next] = true;
				que.push(next);
			}
		}

		if (child == 0)	leaf++;//자식수 없으면 리프노드수 증가
	}

	return leaf;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, p, root, child, eraseNode;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p;

		if (p == -1)
		{
			root = i;
			continue;
		}

		tree[p].push_back(i);
		tree[i].push_back(p);
	}

	cin >> eraseNode;

	visit[eraseNode] = true;//방문할 때 지울애는 방문 X

	if (!visit[root])	cout << bfs(root) << "\n";//root부터 bfs탐색
	else	cout << "0\n";

	return 0;
}