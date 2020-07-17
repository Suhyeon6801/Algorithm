#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 10000;
queue<pair<int, string>> que;
bool visit[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int A, B;
		cin >> A >> B;

		que.push({ A,"" });
		visit[A] = true;

		while (!que.empty())
		{
			int cur = que.front().first;
			string curCmd = que.front().second;
			que.pop();

			if (cur == B)
			{
				cout << curCmd << "\n";
				break;
			}

			int D = (cur * 2) % MAX;
			if (!visit[D])
			{
				que.push({ D, curCmd + "D" });
				visit[D] = true;
			}

			int S;
			if (cur - 1 < 0)	S = 9999;
			else	S = cur - 1;
			if (!visit[S])
			{
				que.push({ S, curCmd + "S" });
				visit[S] = true;
			}

			int L = (cur % 1000) * 10 + cur / 1000;
			if (!visit[L])
			{
				que.push({ L, curCmd + "L" });
				visit[L] = true;
			}

			int R = (cur % 10) * 1000 + (cur / 10);
			if (!visit[R])
			{
				que.push({ R, curCmd + "R" });
				visit[R] = true;
			}
		}

		while (!que.empty())
			que.pop();
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}