#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX = 1010;
int N;
int dist[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, X;
	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(c, dist[a][b]);
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int result = -1;
	for (int i = 1; i <= N; i++)
	{
		result = max(result, dist[i][X] + dist[X][i]);
	}

	cout << result << "\n";

	return 0;
}