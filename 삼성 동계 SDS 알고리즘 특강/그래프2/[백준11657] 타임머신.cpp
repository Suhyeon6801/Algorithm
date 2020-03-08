#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 510;
vector<pair<int, int>> graph[MAX];
int N, M;
int dist[MAX];//����������� ���� K������ �ִܰŸ��� �����ϴ� �迭

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i<M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph[A - 1].push_back(make_pair(B - 1, C));
	}

	bool minusCycle = false;
	fill(dist, dist + N, INF);//�ʱ����
	dist[0] = 0;
	for (int i = 0; i<N; i++)
	{ // (N-1) + 1���� ����. �������� ���� ����Ŭ ���� ���� Ȯ�ο�
		for (int j = 0; j<N; j++)
		{
			// N-1���� ������ ���� �� ������ i+1�� ������ ���Ŀ��� �ִܰ�� ����
			for (int p = 0; p<graph[j].size(); p++)
			{
				int next = graph[j][p].first;
				int d = graph[j][p].second;
				if (dist[j] != INF && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;

					// N��° ������ ���� ���ŵǸ� ���� ����Ŭ�� ���� -> �ִܰŸ� ���� �� ����.
					if (i == N - 1) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle)
	{
		cout << "-1\n";
	}
	else
	{
		for (int i = 1; i <N; i++)
		{
			if (dist[i] != INF)
				cout << dist[i] << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;
}

