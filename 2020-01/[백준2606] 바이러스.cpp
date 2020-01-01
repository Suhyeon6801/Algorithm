#include <iostream>
#include <vector>
using namespace std;

const int MAX = 110;
vector <int> v[MAX];
bool visit[MAX] = { 0, };
int cnt = 0;

int dfs(int x)
{
	visit[x] = true;

	cnt++;
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (!visit[y])
			dfs(y);
	}

	return cnt;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << dfs(1)-1 << "\n";

	return 0;
}
