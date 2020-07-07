//출력초과 관련 문제 -> int를 long long으로!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
const int MAX = 510;
vector<pair<int, int>> graph[MAX];
int N, M;
long long dist[MAX];//출발정점에서 정점 K까지의 최단거리를 저장하는 배열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph[A - 1].push_back(make_pair(B - 1, C));
	}

	bool minusCycle = false;
	fill(dist, dist + N, INF);//초기상태
	dist[0] = 0;
	for (int i = 0; i < N; i++)
	{ // (N-1) + 1번의 루프. 마지막은 음의 싸이클 존재 여부 확인용
		for (int j = 0; j < N; j++)
		{
			// N-1번의 루프에 걸쳐 각 정점이 i+1개 정점을 거쳐오는 최단경로 갱신
			for (int p = 0; p < graph[j].size(); p++)
			{
				long long next = graph[j][p].first;
				long long d = graph[j][p].second;
				if (dist[j] != INF && dist[next] > dist[j] + d)
				{
					dist[next] = dist[j] + d;

					// N번째 루프에 값이 갱신되면 음의 싸이클이 존재 -> 최단거리 구할 수 없음.
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
		for (int i = 1; i < N; i++)
		{
			if (dist[i] != INF)
				cout << dist[i] << "\n";
			else
				cout << "-1\n";
		}
	}
}