#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 2001;
int N, M;
vector<int> v[MAX];
vector<int> relation;
bool visited[MAX];
bool isOk = false;

void dfs(int cur, int cnt)//cur현재 사람, cnt 조사할 관계수
{
	if (cnt == 4)
	{
		isOk = true;
		return;
	}

	visited[cur] = true;

	for (int i = 0; i <v[cur].size() ; i++)//dfs돌려서 관계 확인하고,
	{
		int next = v[cur][i];
		if (!visited[next])
			dfs(next, cnt+1);
	}

	visited[cur] = false;//초기화.
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
		if (isOk)	break;
	}

	if (isOk)	cout << "1\n";
	else
		cout << "0\n";

	return 0;
}