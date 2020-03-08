#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10010;
vector<int> g[MAX];
int order[MAX];
bool isCut[MAX];
int cnt = 1;

int dfs(int x, bool isRoot)
{
	order[x] = cnt++; // dfs방문순서 저장
	int ret = order[x];

	int child = 0;//자식수 count

	for (int i = 0; i < g[x].size(); i++)
	{
		int next = g[x][i];

		//이미 탐색된 정점이면 현재 점의 방문순서와 탐색된 정점의 방문순서 중 최솟값찾기
		//A를 거치지 않고 정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점. 간다면 단절점이 아니다.

		if (order[next])//방문을 이미 함.
		{
			ret = min(ret, order[next]);
			continue;
		}

		child++;//자식개수 하나 늘려주고(next탐색했으니까) next로 넘어감
		int prev = dfs(next, false);// 그 next가 루트가 아니라면
		if (!isRoot&&prev >= order[x])
			isCut[x] = true;

		ret = min(ret, prev);
	}

	if (isRoot)//루트라면, child수가 2이상이면 단절점.
	{
		if (child >= 2)
			isCut[x] = true;
	}

	return ret;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//정점A가 루트라면, 자식수가 2개 이상이면 단절점이다.
	//정점A가 루트가 아니면, A를 거치지 않고 정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점. 간다면 단절점이 아니다.
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B;
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	for (int i = 1; i <= V; i++)
	{
		if (!order[i])
			dfs(i, true);
	}

	int count = 0;
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i])	count++;
	}

	cout << count << "\n";
	for (int i = 1; i <= V; i++)
	{
		if (isCut[i])
			cout << i << " ";
	}

	return 0;
}