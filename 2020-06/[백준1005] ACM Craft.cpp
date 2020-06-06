#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int building_time[MAX];
int indegree[MAX];
int result[MAX];//해당 건물을 짓는데 필요한 최소시간.

void init()
{
	memset(indegree, 0, sizeof(indegree));
	memset(result, 0, sizeof(result));
	memset(building_time, 0, sizeof(building_time));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		init();
		vector<int> v[MAX];
		int N, K, X, Y, W;
		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> building_time[i];

		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			v[X].push_back(Y);
			indegree[Y]++;
		}

		cin >> W;

		queue<int> que;
		for (int i = 1; i <= N; i++)
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
				//next건물의 최소 건설시작 시간 갱신.
				result[next] = max(result[next], result[cur] + building_time[cur]);

				indegree[next]--;
				if (indegree[next] == 0)
				{
					que.push(next);
				}
			}
		}
		cout << result[W] + building_time[W] << "\n";
	}
	
	return 0;
}