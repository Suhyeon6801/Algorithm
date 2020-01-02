#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;
bool check[MAX] = { 0, };
int n, k;
int sec = 0;
queue <pair<int, int>> que;

void bfs(int x, int cnt)
{
	que.push(make_pair(x, cnt));
	check[x] = true;

	while (!que.empty())
	{
		int cur = que.front().first;
		int sec = que.front().second;
		que.pop();

		if (cur == k)
		{
			cout << sec << " ";
			break;
		}

		int x1 = cur - 1;
		int x2 = cur + 1;
		int x3 = cur * 2;

		if ((x1 >= 0 && x1 <= MAX) && !check[x1])
		{
			que.push(make_pair(x1, sec + 1));
			check[x1] = true;
		}

		if ((x2 >= 0 && x2 <= MAX) && !check[x2])
		{
			que.push(make_pair(x2, sec + 1));
			check[x2] = true;
		}

		if ((x3 >= 0 && x3 <= MAX) && !check[x3])
		{
			que.push(make_pair(x3, sec + 1));
			check[x3] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	bfs(n, 0);

	return 0;
}
