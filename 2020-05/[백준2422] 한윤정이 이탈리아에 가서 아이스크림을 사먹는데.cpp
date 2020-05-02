#include <iostream>
using namespace std;

int N, M;
bool arr[210][210];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (!arr[i][j])
			{
				for (int k = j + 1; k <= N; k++)
				{
					if (!arr[i][k] && !arr[k][j])
						cnt++;
				}
			}

		}
	}

	cout << cnt << "\n";

	return 0;
}