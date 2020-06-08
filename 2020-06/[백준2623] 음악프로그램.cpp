#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1010;
int arr[MAX];
vector<int> v[MAX];
int indegree[MAX];
queue<int> que;
vector<int> result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> K;

		for (int j = 0; j < K; j++)
			cin >> arr[j];

		for (int j = 0; j < K -1; j++)
		{
			int a = arr[j];
			int b = arr[j + 1];
			indegree[b]++;
			v[a].push_back(b);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		result.push_back(cur);

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			indegree[next]--;

			if (indegree[next] == 0)
				que.push(next);
		}
	}

	if (result.size() != N)	cout << "0\n";
	else
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}

	return 0;
}