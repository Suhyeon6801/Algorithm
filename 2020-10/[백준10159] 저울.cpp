#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int arr[110][110];
int N, M;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)	arr[i][j] = 0;
			else	arr[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)	continue;

				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)	continue;
			if (arr[i][j] == INF && arr[j][i] == INF)	cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}