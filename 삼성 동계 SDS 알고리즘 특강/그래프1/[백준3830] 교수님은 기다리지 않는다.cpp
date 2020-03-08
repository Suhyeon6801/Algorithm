#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;
vector <pair<int, long long>> v[MAX];//도착, 무게차이
long long weight[MAX];
long long p[MAX];
long long visit[MAX];
long long Q[MAX][3];

int find(int x)
{
	if (p[x] == x)	return x;
	else
		return p[x] = find(p[x]);
}

void merge(int a, int b)
{
	p[find(b)] = find(a);
}

void dfs(int x, long long w)
{
	visit[x] = true;
	weight[x] = w;

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i].first;
		long long gap = v[x][i].second;
		if (!visit[y])
		{
			dfs(y, w + gap);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long c;
	char cmd;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)	break;

		for (int i = 0; i <= n; i++)//초기화
		{
			visit[i] = false;
			weight[i] = 0;
			p[i] = i;
			v[i].clear();
		}

		for (int i = 0; i < m; i++)
		{
			//1=시작, 2=도착
			cin >> cmd >> Q[i][1] >> Q[i][2];
			if (cmd == '!')
			{
				cin >> c;
				Q[i][0] = 0;
				v[Q[i][1]].push_back(make_pair(Q[i][2], c));
				v[Q[i][2]].push_back(make_pair(Q[i][1], -c));
			}
			else if (cmd == '?')
			{
				Q[i][0] = 1;
			}
		}

		//cout << "dfs start" << endl;
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
				dfs(i, 0);
		}

		for (int i = 0; i < m; i++)
		{
			if (Q[i][0] == 0)
			{
				merge(Q[i][1], Q[i][2]);
			}
			else if (Q[i][0] == 1)
			{
				if (find(Q[i][1]) != find(Q[i][2]))
					cout << "UNKNOWN\n";
				else
					cout << weight[Q[i][2]] - weight[Q[i][1]] << "\n";
			}
		}
	}

	return 0;
}