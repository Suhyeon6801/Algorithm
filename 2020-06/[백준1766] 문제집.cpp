#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int MAX = 32000 + 1;
int indegree[MAX];
vector<int> v[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		v[A].push_back(B);
		indegree[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			pq.push(i);
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		
		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			indegree[next]--;

			if (indegree[next] == 0)
				pq.push(next);
		}
	}

	return 0;
}