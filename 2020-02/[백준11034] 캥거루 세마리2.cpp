#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[110][110][110];//left,mid,right일때 이동한 최대 횟수

int solve(int left, int mid, int right)
{
	if (left + 1 == mid && mid + 1 == right)	return 0;

	int& ret = dp[left][mid][right];
	if (ret != -1)	return ret;

	ret = -1;
	for (int i = left + 1; i < mid; i++)
	{
		ret = max(ret, solve(left, i, mid) + 1);
	}

	for (int i = mid + 1; i < right; i++)
	{
		ret = max(ret, solve(mid, i, right) + 1);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	while (cin >> a >> b >> c)
	{
		memset(dp, -1, sizeof(dp));
		cout << solve(a, b, c) << "\n";
	}
	
	return 0;
}