#include <iostream>
using namespace std;

const int INF = 987654321;
int N, M, H;
int map[20][30];
bool visit[20][30];//b와 b+1사다리가 a가로선으로 연결
int answer = INF;

bool isPossible()//사다리게임해서 조건 만족하는지
{
	for (int i = 1; i <= N; i++)
	{
		int cur = i;
		for (int j = 1; j <= H; j++)
		{
			if (visit[cur][j])	cur = cur + 1;
			else if (visit[cur - 1][j])	cur = cur - 1;
		}

		if (cur != i)	return false;
	}

	return true;
}

void dfs(int cnt, int idx)
{
	if (cnt > 3)
	{
		return;
	}

	if (isPossible())
	{
		if (answer > cnt)
			answer = cnt;

		return;
	}

	for (int i = idx; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (visit[j][i])	continue;
			if (visit[j - 1][i])	continue;
			if (visit[j + 1][i])	continue;

			visit[j][i] = true;
			dfs(cnt + 1, i);
			visit[j][i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{	
		cin >> a >> b;
		visit[b][a] = true;
	}

	dfs(0, 1);

	if (answer == INF)	cout << "-1\n";
	else
		cout << answer << "\n";

	return 0;
}