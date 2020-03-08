#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int N, M;
vector<pair<int, int>> graph[MAX];//연결된 도시, 도로길이
int depth[MAX];
int par[MAX][20];
int distMAX[MAX][20];
int distMin[MAX][20];

void dfs(int cur)
{
	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next = graph[cur][i].first;
		int len = graph[cur][i].second;

		if (depth[next] == -1)
		{
			depth[next] = depth[cur] + 1;
			par[next][0] = cur;
			distMAX[next][0] = len;
			distMin[next][0] = len;
			dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i <= N; i++)//초기화
	{
		graph[i].clear();
		depth[i] = -1;
		for (int j = 0; j <= 20; j++)
		{
			distMAX[i][j] = 0;
			distMin[i][j] = 1000001;
			par[i][j] = 0;
		}
	}

	for (int i = 0; i < N - 1; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].push_back(make_pair(B, C));
		graph[B].push_back(make_pair(A, C));
	}

	depth[1] = 0;
	par[1][0] = 1;
	dfs(1);

	//dp 만들기
	//**주의!! min, max 는 부모노드있는 노드의!!
	for (int j = 1; j < 18; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			par[i][j] = par[par[i][j - 1]][j - 1];
			distMAX[i][j] = max(distMAX[i][j - 1], distMAX[par[i][j - 1]][j - 1]);
			distMin[i][j] = min(distMin[i][j - 1], distMin[par[i][j - 1]][j - 1]);
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int D, E;
		int getMin = 1000001;
		int getMax = -1;
		cin >> D >> E;

		//두도시의 depth가 다를 경우 하나로 맞춰준다.
		if (depth[D] < depth[E])
			swap(D, E);

		for (int j = 18 - 1; j >= 0; j--)
		{
			while (D != E && (depth[par[D][j]] >= depth[E]))
			{
				getMin = min(getMin, distMin[D][j]);
				getMax = max(getMax, distMAX[D][j]);
				D = par[D][j];
			}
		}

		//두 도시의 LCA가 같지 않으면  LCA찾아가기
		//LCA를 찾아가면서 최소, 최대 갱신
		for (int j = 18 - 1; j >= 0 && D != E; j--)
		{
			while (D != E && (par[D][j] != par[E][j]))
			{
				getMin = min(getMin, min(distMin[D][j], distMin[E][j]));
				getMax = max(getMax, max(distMAX[D][j], distMAX[E][j]));
				D = par[D][j];
				E = par[E][j];
			}
		}

		if (D != E)//두 도시가 동일하지 않다면, LCA는 두 도시의 부모도시임.
		{
			getMin = min(getMin, min(distMin[D][0], distMin[E][0]));
			getMax = max(getMax, max(distMAX[D][0], distMAX[E][0]));
		}

		cout << getMin << " " << getMax << "\n";
	}
	return 0;
}