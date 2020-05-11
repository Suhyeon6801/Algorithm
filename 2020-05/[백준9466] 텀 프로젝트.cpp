#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100010;
int N;
int arr[MAX];
bool visit[MAX];
bool isDone[MAX];
int cnt;

void dfs(int x)
{
	visit[x] = true;

	int next = arr[x];
	if (!visit[next])
		dfs(next);
	else if (!isDone[next])
	{
		for (int i = next; i != x; i = arr[i])
			cnt++;
		cnt++;
	}

	isDone[x] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(isDone, 0, sizeof(isDone));
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
				dfs(i);
		}

		cout << N - cnt << "\n";
	}
	
	return 0;
}