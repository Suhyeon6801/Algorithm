#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int importance[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		int N, M;
		cin >> N >> M;

		queue<pair<int, int>> que;//index, 중요도
		priority_queue<int> pq;//중요도 내림차순
		memset(importance, 0, sizeof(importance));

		for (int i = 0; i < N; i++)
		{
			cin >> importance[i];

			que.push(make_pair(importance[i], i));
			pq.push(importance[i]);
		}

		int cnt = 0;
		while (!que.empty())
		{
			int cur = que.front().first;
			int index = que.front().second;
			que.pop();

			if (cur == pq.top())
			{
				cnt++;
				pq.pop();

				if (index == M)
				{
					cout << cnt << "\n";
					break;
				}
			}
			else
				que.push(make_pair(cur, index));
		}

		//que, pq비워주기
		while (!que.empty())
		{
			que.pop();
		}

		while (!pq.empty())
		{
			pq.pop();
		}
	}
	
	return 0;
}