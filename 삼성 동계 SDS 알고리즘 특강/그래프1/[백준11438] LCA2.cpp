#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;
vector<int> graph[MAX];
int parent[MAX][20];// parent[i][k]:i의 2^k번째 부모
int depth[MAX];//정점의 깊이

void TreebyDFS(int x)//dfs로 트리 제작, parent[i][0], depth 배열 채우기
{
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (depth[y] == -1)
		{
			parent[y][0] = x;
			depth[y] = depth[x] + 1;
			TreebyDFS(y);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(parent, -1, sizeof(parent));
	fill(depth, depth + n, -1);
	depth[0] = 0;

	//트리만들기
	TreebyDFS(0);

	//parent 채우기
	for (int j = 0; j < 18 - 1; j++)
	{
		for (int i = 1; i < n; i++)
		{
			if (parent[i][j] != -1)
			{
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		if (depth[u] < depth[v])//꼭 depth[u]>=depth[v]가 되어야 함!	
			swap(u, v);

		int diff = depth[u] - depth[v];

		//깊이 차이를 없애면서 u를 이동
		for (int j = 0; diff; j++)
		{
			if (diff % 2 != 0)	u = parent[u][j];
			diff /= 2;
		}

		//u와v가 다르다면 동시에 일정 높이만큼 위로 이동
		if (u != v)
		{
			for (int j = 18 - 1; j >= 0; j--)
			{
				if (parent[u][j] != -1 & parent[u][j] != parent[v][j])
				{
					u = parent[u][j];
					v = parent[v][j];
				}
			}

			//마지막에는 두 정점의 부모가 같으니까 한번더 올린다.
			u = parent[u][0];
		}
		cout << u + 1 << "\n";
	}

	return 0;
}