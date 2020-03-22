#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 110;
const int INF = 987654321;
int N, M;
int map[MAX][MAX];
int island[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int p[10];
int dist[10][10];

struct Edge {
	int from, to, cost;
};
Edge edge[10];

bool comp(Edge e1, Edge e2)
{
	return e1.cost < e2.cost;
}

void dfs(int y, int x, int num)
{
	visit[y][x] = true;
	island[y][x] = num;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
		if (!visit[ny][nx] && map[ny][nx] == 1)
			dfs(ny, nx, num);
	}
}

void makeBridge(int y, int x, int start, int dest, int d)
{
	int len = 0;
	int ny, nx;
	while (1)
	{
		ny = y + dy[d];
		nx = x + dx[d];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M || island[ny][nx]==start)	break;//외곽 및 내부
		if (island[ny][nx]!=0 && island[ny][nx] != dest)	break;//찾고자하는 섬이 아닐 경우도 break

		if(island[ny][nx] != 0 && island[ny][nx]==dest)
		{
			if (len >= 2)
			{
				if (dist[start][dest] > len)
				{
					dist[start][dest] = len;
					dist[dest][start] = len;
				}
			}
			else
				break;//길이가 2가 안되면 걍 break
		}


		len++;
		y = ny;
		x = nx;
	}
}

int find(int x)
{
	if (x == p[x])
		return x;
	else
		return find(p[x]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	p[pb] = pa;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	//섬 번호 붙이기(단지번호)
	int num = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j] && map[i][j] == 1)
			{
				dfs(i, j, num++);
			}
		}
	}

	//섬 -  섬 최소 거리 찾기
	for (int i = 1; i < num; i++)
	{
		for (int j = 1; j < num; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (island[i][j] != 0)
			{
				for (int k = 1; k < num; k++)
				{
					if (k != island[i][j])
					{
						for (int d = 0; d < 4; d++)
							makeBridge(i, j, island[i][j], k, d);
					}
				}
			}
		}
	}

	int idx = 0;
	for (int i = 1; i < num; i++)
	{
		for (int j = 1; j < num; j++)
		{
			if (dist[i][j] == INF || dist[i][j]==0)	continue;
			else
			{
				edge[idx].from = i;
				edge[idx].to = j;
				edge[idx].cost = dist[i][j];
				idx++;
			}
		}
	}
	
	//크루스칼
	sort(edge, edge + idx, comp);//cost를 오름차순으로 정렬

	for (int i = 1; i < num; i++)
		p[i] = i;

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < idx; i++)
	{
		if (find(edge[i].from) != find(edge[i].to))
		{
			merge(edge[i].from, edge[i].to);
			ans += edge[i].cost;
			cnt++;

			if (cnt == num - 2)
				break;
		}
	}
	
    //최종적으로 다 연결 되었는지 확인!
	int temp = find(1);
	bool flag = true;
	for (int i = 2; i < num; i++)
	{
		if (temp != find(i))
			flag = false;
	}

	if (!flag)	cout << "-1\n";
	else
		cout << ans << "\n";


	return 0;
}