#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;
vector<int> graph[MAX];
int parent[MAX][20];// parent[i][k]:i�� 2^k��° �θ�
int depth[MAX];//������ ����

void TreebyDFS(int x)//dfs�� Ʈ�� ����, parent[i][0], depth �迭 ä���
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

	//Ʈ�������
	TreebyDFS(0);

	//parent ä���
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

		if (depth[u] < depth[v])//�� depth[u]>=depth[v]�� �Ǿ�� ��!	
			swap(u, v);

		int diff = depth[u] - depth[v];

		//���� ���̸� ���ָ鼭 u�� �̵�
		for (int j = 0; diff; j++)
		{
			if (diff % 2 != 0)	u = parent[u][j];
			diff /= 2;
		}

		//u��v�� �ٸ��ٸ� ���ÿ� ���� ���̸�ŭ ���� �̵�
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

			//���������� �� ������ �θ� �����ϱ� �ѹ��� �ø���.
			u = parent[u][0];
		}
		cout << u + 1 << "\n";
	}

	return 0;
}