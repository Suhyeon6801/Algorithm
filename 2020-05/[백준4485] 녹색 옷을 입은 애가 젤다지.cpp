#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <functional>
using namespace std;

const int MAX = 150;
const int INF = 987654321;
int map[MAX][MAX];
int dist[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool visit[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int tc = 1;

	while (1)
	{
		cin >> N;
		if (N == 0)	break;

		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = INF;

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({ 0,{0,0} });//cost, 위치
		visit[0][0] = true;
		dist[0][0] = map[0][0];

		while (!pq.empty())
		{
			int cost = pq.top().first;
			int y = pq.top().second.first;
			int x = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				int nextCost = cost + map[ny][nx];

				if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;

				if (!visit[ny][nx] && dist[ny][nx] > nextCost)
				{
					visit[ny][nx] = true;
					dist[ny][nx] = nextCost;
					pq.push({ nextCost,{ny,nx} });
				}
			}
		}

		cout << "Problem " << tc << ": " << dist[0][0] + dist[N - 1][N - 1] << "\n";
		tc++;
	}

	return 0;
}