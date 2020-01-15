#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 40;
const int INF = 987654321;
int dist[10010];
int ghost[MAX][MAX];
int gravestone[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct Edge
{
	int from;
	int to;
	int cost;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//과거로 돌아가는 경우 -> 벨만포드 알고리즘 사용
	int w, h, g, e;//w,h -> map, g-> 묘비,  e->귀신구멍정보
	while (1)
	{
		Edge edge[5000];

		cin >> w >> h;
		if (w == 0 && h == 0)	break;

		for (int i = 0; i < w*h; i++)//dist배열 초기화
			dist[i] = INF;

		memset(ghost, 0, sizeof(ghost));//초기화
		memset(gravestone, 0, sizeof(gravestone));//초기화

		int x, y;//묘비 위치
		int x1, y1, x2, y2, t;
		cin >> g;
		for (int i = 0; i < g; i++)
		{
			cin >> x >> y;
			gravestone[y][x] = true;///여기에 묘비 있다.
		}

		int edgeIdx = 0;
		cin >> e;
		for (int i = 0; i < e; i++)
		{
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			ghost[y1][x1] = true;
			edge[edgeIdx].from = y1*w + x1;
			edge[edgeIdx].to = y2*w + x2;
			edge[edgeIdx].cost = t;
			edgeIdx++;
		}//입력끝!

		 //이동
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (gravestone[i][j] || ghost[i][j] || (i == h - 1 && j == w - 1))
					continue;

				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 || nx < 0 || nx >= w || ny >= h || gravestone[ny][nx])	continue;

					edge[edgeIdx].from = i*w + j;
					edge[edgeIdx].to = ny*w + nx;
					edge[edgeIdx].cost = 1;
					edgeIdx++;

				}
			}
		}

		//최단거리 찾기 - 벨만포드 알고리즘
		dist[0] = 0;
		bool cycle = false;
		int v = w*h - g;//정점의 개수는 전체-묘비의 개수
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < edgeIdx; j++)
			{
				int cur = edge[j].from;
				int next = edge[j].to;
				int d = edge[j].cost;

				if (dist[cur] != INF&&dist[next] > dist[cur] + d)
				{
					dist[next] = dist[cur] + d;

					if (i == v - 1)	cycle = true;
				}
			}
		}

		if (cycle)	cout << "Never\n";
		else if (dist[w*h - 1] == INF)	cout << "Impossible\n";
		else
			cout << dist[w*h - 1] << "\n";

	}

	return 0;
}