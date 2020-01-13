#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 32010;
int indegree[MAX];
vector<int> v[MAX];//그래프 인접리스트 만들기

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> que;
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);
		indegree[b]++;//indegree차수 증가, 정보저장
	}

	for (int i = 1; i <= n; i++)//indegree차수가 0이면 queue에 담는다.
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	while (!que.empty())//que가 빌때까지 
	{
		int cur = que.front();//현재 순서 뽑느다.
		que.pop();
		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++)//그 순서에 연결된 정점들의 indegree를 하나씩 빼고
		{
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)//indegree가 0이 되는 정점은 que에 담는다.
				que.push(next);
		}
	}

	return 0;
}