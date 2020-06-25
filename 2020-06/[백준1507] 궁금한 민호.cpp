#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
int dist[30][30];
bool road[30][30];
int N;
int ret;

void floyd()
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (k == i || i == j || j == k)	continue;
				else if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					ret = -1;
					return;
				}
				else if (dist[i][j] == dist[i][k] + dist[k][j])//거쳐가는 경로가 한방이랑 같다면 거쳐가는 도로를 선택
					road[i][j] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> dist[i][j];
		}
	}

	memset(road, true, sizeof(road));
	floyd();

	int sum = 0;
	if (ret != -1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (road[i][j])
					sum += dist[i][j];
			}
		}

		//i->j, j->i 반복 => 2로 나눠야지!
		cout << sum / 2 << "\n";
	}
	else
		cout << "-1\n";

	return 0;
}