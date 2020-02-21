#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000010;
bool visit[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int F, S, G, U, D;
	queue<int> que;

	cin >> F >> S >> G >> U >> D;

	bool flag = false;
	int dist = 0;
	que.push(S);
	visit[S] = true;

	while (!que.empty())
	{
		int size = que.size();
		while (size--)
		{
			int cur = que.front();
			que.pop();

			if (cur == G)
			{
				flag = true;
				break;
			}

			int next1 = cur + U;
			int next2 = cur - D;

			if (next1 <= F && !visit[next1])
			{
				visit[next1] = true;
				que.push(next1);
			}

			if (next2 >= 1 && !visit[next2])
			{
				visit[next2] = true;
				que.push(next2);
			}
		}

		if (flag)
			break;

		dist++;
	}

	if (flag)
		cout << dist << "\n";
	else
		cout << "use the stairs\n";

	return 0;
}