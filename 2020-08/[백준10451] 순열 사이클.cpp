#include <iostream>
#include <cstring>
using namespace std;

bool check[1010];
bool isDone[1010];
int arr[1010];

void dfs(int cur)
{
	check[cur] = true;
	int next = arr[cur];

	if (!check[next])
		dfs(next);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N, cycle = 0;
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				cycle++;
				dfs(i);
			}
		}

		cout << cycle << "\n";
		memset(check, 0, sizeof(check));
	}

	return 0;
}