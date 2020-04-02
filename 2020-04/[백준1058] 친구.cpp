#include <iostream>
#include <vector>
#include<cstring>
#include <algorithm>
using namespace std;

const int MAX = 60;
const int INF = 987654321;
int dist[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char c;
			cin >> c;

			if (i == j)
				dist[i][j] = 0;

			if (c == 'Y')
			{
				dist[i][j] = 1;
			}
			else
				dist[i][j] = INF;
		}
	}

    //플로이드-와샬로 친구간의 거리구하기
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j || j == k || i == k)	continue;
				else
					dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	int cnt = 0;
	int getMax = -1;
    //서로 친구이거나 한다리 건너서 친구일 때만 cnt++
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (dist[i][j] <= 2)
					cnt++;
			}
		}
		getMax = max(cnt, getMax);
	}

	cout << getMax << "\n";
	
	return 0;
}