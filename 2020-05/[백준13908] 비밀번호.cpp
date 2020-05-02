#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool visit[10];
int ans = 0;

void dfs(int cnt, int idx)
{
	if (idx == n)
	{
		if (cnt != m)	return;
		
		ans++;
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (visit[i])
		{
			visit[i] = false;
			dfs(cnt+1, idx+1);
			visit[i] = true;
			continue;
		}

		dfs(cnt, idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
		visit[arr[i]] = true;
	}

	dfs(0,0);
	cout << ans << "\n";

	return 0;
}