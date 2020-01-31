#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, char>> graph[1010];
char card[1010];
int N, M, K;
int dp[1010][1010];//n카드 일때, m카드 까지 왔을 때 최대 점수

int dfs(int pos, int cnt)
{
	if (cnt == N)	return 0;//기저조건
	
	int &ret = dp[pos][cnt];
	if (ret != -1)	return ret;

	ret = 0;
	for (int i = 0; i < graph[pos].size(); i++)
	{
		int next = graph[pos][i].first;
		char color = graph[pos][i].second;

		if (color == card[cnt])
			ret = max(ret, dfs(next, cnt + 1) + 10);
		else
			ret = max(ret, dfs(next, cnt + 1));
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	//cin.ignore();
	for (int i = 0; i < N; i++)
		cin >> card[i];

	int a, b;
	char c;
	cin >> M >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	memset(dp, -1, sizeof(dp));
	cout << dfs(1, 0);

	return 0;
}