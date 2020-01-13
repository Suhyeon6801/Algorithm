#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 510;
int indegree[MAX];
int defaultTime[MAX];
int addTime[MAX] = { 0, };
queue<int> que;
vector<int> v[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> defaultTime[i];

		while (1)
		{
			cin >> num;
			if (num == -1)	break;

			v[num].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			que.push(i);
	}

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			indegree[next]--;
			if (indegree[next] == 0)
			{
				que.push(next);
			}

			int ConstructTime = defaultTime[cur] + addTime[cur];
			if (ConstructTime > addTime[next])
				addTime[next] = ConstructTime;

		}
	}

	for (int i = 1; i <= n; i++)
		cout << defaultTime[i] + addTime[i] << "\n";


	return 0;
}