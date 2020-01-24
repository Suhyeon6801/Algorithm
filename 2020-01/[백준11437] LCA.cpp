#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100010;
vector<int> graph[MAX];
int par[MAX][20];
int depth[MAX];

void makeTree(int cur)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i];
		if (depth[next] == -1)
		{
			par[next][0] = cur;//next의 부모는 cur
			depth[next] = depth[cur] + 1;//depth갱신
			makeTree(next);
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
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	memset(par, -1, sizeof(par));
	fill(depth + 1, depth + n + 1, -1);

	depth[1] = 0;
	makeTree(1);


	//par채우기
	for (int j = 0; j < 18; j++)
	{
		for (int i = 2; i <= n; i++)
		{
			if (par[i][j] != -1)
				par[i][j + 1] = par[par[i][j]][j];
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (depth[a] < depth[b])
			swap(a, b);

		int diff = depth[a] - depth[b];
		for (int j = 0; diff; j++)
		{
			if (diff % 2 != 0)	a = par[a][j];
			diff /= 2;
		}

		if (a != b)
		{
			for (int j = 18 -1; j >= 0; j--)
			{
				if (par[a][j] != -1 && par[a][j] != par[b][j])
				{
					a = par[a][j];
					b = par[b][j];
				}
			}

			a = par[a][0];
		}

		cout << a << "\n";
	}


	return 0;
}