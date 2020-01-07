#include <iostream>
using namespace std;

int col[20];
int n;
int cnt = 0;

bool check(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (col[i] == col[x])	return false;
		else if (col[i] - col[x] == x - i)	return false;
		else if (col[x] - col[i] == x - i)	return false;
	}
	return true;
}

void dfs(int x)
{
	if (x == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		col[x] = i;
		if (check(x))
		{
			dfs(x + 1);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dfs(0);

	cout << cnt << "\n";

	return 0;
}