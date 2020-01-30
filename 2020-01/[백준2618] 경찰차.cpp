//DP+DFS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1010][1010];//경찰차1이 i사건, 경찰차2가 j사건을 마지막으로 처리했을 때 이동한 거리의 최소값.
pair<int,int> p[1010];
int order[1010];//i사건에 대한 경찰차 번호
int n;//동서방향 도로의 개수
int w;//처리해야하는 사건 개수

int dist(pair<int,int> p1, pair<int,int>p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int dfs(int x, int y)//이동한 총 거리
{
	if (x == w || y == w)return 0;
	int &ret = dp[x][y];
	if (ret != -1)return ret;
	int fir, sec;
	if (!x)
		fir = dfs(max(x, y) + 1, y) + dist(p[max(x, y) + 1], { 1,1 });
	else
		fir = dfs(max(x, y) + 1, y) + dist(p[max(x, y) + 1], p[x]);
	if (!y)
		sec = dfs(x, max(x, y) + 1) + dist(p[max(x, y) + 1], { n,n });
	else
		sec = dfs(x, max(x, y) + 1) + dist(p[max(x, y) + 1], p[y]);
	return ret = min(fir, sec);

}

void solve(int x, int y)//사건에 대한 경찰차 번호
{
	if (x == w || y == w)	return;
	int fir, sec;
	if (!x)
		fir = dfs(max(x, y) + 1, y) + dist(p[max(x, y) + 1], { 1,1 });
	else
		fir = dfs(max(x, y) + 1, y) + dist(p[max(x, y) + 1], p[x]);
	if (!y)
		sec = dfs(x, max(x, y) + 1) + dist(p[max(x, y) + 1], { n,n });
	else
		sec = dfs(x, max(x, y) + 1) + dist(p[max(x, y) + 1], p[y]);

	if (fir < sec) {
		order[max(x, y) + 1] = 1;
		solve(max(x, y) + 1, y);
	}
	else {
		order[max(x, y) + 1] = 2;
		solve(x, max(x, y) + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w;
	for (int i = 1; i <= w; i++)
		cin >> p[i].first >> p[i].second;

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << "\n";
	solve(0, 0);
	for (int i = 1; i <= w; i++)
	{
		cout << order[i] << "\n";
	}

	return 0;
}