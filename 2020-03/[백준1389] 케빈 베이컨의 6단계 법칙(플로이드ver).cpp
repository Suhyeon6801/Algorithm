#include <iostream>
#include<algorithm>
using namespace std;

const int INF = 987654321;
int dist[110][110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int a, b;
	cin >> N >> M;

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
		cin >> a >> b;
		
		dist[a][b] = 1;
		dist[b][a] = 1;
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

	int getMin = INF;
	int idx;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int j = 1; j <= N; j++)
		{
			sum+=dist[i][j];
		}

		if (getMin > sum)
		{
			getMin = sum;
			idx = i;
		}
	}
	cout <<idx<< "\n";
	
	
	return 0;
}