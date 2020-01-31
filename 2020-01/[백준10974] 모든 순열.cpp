#include <iostream>
using namespace std;

int n;
int arr[10];
bool check[10];

void dfs(int x)
{
	if (x == n)
	{
		for (int i = 0; i < x; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			arr[x] = i;
			check[i] = true;
			dfs(x + 1);
			check[i] = false;
			arr[x] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	dfs(0);

	return 0;
}