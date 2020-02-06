#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 110;
int n, m;
int p1, p2;
vector<int> v[MAX];
queue<int> que;
bool visit[MAX];
int cnt = 0;
bool flag = false;

void bfs(int p)
{
	que.push(p);
	visit[p] = true;

	while (!que.empty())
	{
		int size = que.size();
		while (size--)
		{
			int cur = que.front();
			que.pop();

			if (cur == p2)
			{
				flag = true;
				break;
			}

			for (int i = 0; i < v[cur].size(); i++)
			{
				int next = v[cur][i];
				if (!visit[next])
				{
					que.push(next);
					visit[next] = true;
				}
			}
		}
		cnt++;

		if (flag)
			break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> n >> p1 >> p2 >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	bfs(p1);

	if (!flag)
		cout << "-1\n";
	else
		cout << cnt - 1 << "\n";
	
	return 0;
}