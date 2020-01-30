//DP+DFS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = -987654321;
int dp[310][310];//i도시까지 이동하고 항공편 j를 이용했을 때, 얻는 최대 기내식 점수
int n, m, k;
int arr[310][310];

int dfs(int pos, int cnt)
{
	if (pos == n)	return 0;
	if (cnt == m)	return INF;//m개 이하
	int &ret = dp[pos][cnt];
	if (ret != -1)	return ret;

	ret = INF;
	for (int i = pos + 1; i <= n; i++)
	{
		if (arr[pos][i] != 0)
			ret = max(ret, arr[pos][i] + dfs(i, cnt + 1));
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//1~n까지 이동시 k이하로 항공로 사용했을 때 얻는 최대 기내식 점수
	int a, b, c;
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c;
		arr[a][b] = max(arr[a][b], c);//a->b이용시 얻는 최대 기내식 점수
	}
	memset(dp, -1, sizeof(dp));

	if (dfs(1, 1) > 0)	cout << dfs(1, 1);
	else
		cout << "0\n";

	return 0;
}