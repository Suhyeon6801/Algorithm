#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9; // 절대 나올 수 없는 경로값

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, dist[100][100];
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
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
		dist[a - 1][b - 1] = min(dist[a - 1][b - 1], c);
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dist[i][j] < INF)
				cout << dist[i][j] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}

	return 0;
}