//플로이드 와샬 알고리즘
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 510;
int dist[MAX][MAX];
int INF = 9999;
int isConnect[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != INF)
			{
				isConnect[i]++;
				isConnect[j]++;

				if (isConnect[i] == n - 1)	cnt++;
				if (isConnect[j] == n - 1)	cnt++;
			}
		}
	}
	cout << cnt << "\n";

	return 0;
}