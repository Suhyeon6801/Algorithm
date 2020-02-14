#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 510;
pair<int, int> cable[MAX];
int dp[MAX];

int Search(int start, int end, int target)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (dp[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return end + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cable[i].first >> cable[i].second;

	sort(cable + 1, cable + 1 + n);

	int dpIdx = 1;
	int idx = 2;
	dp[1] = cable[1].second;

	while (idx <= n)
	{
		if (dp[dpIdx] < cable[idx].second)
		{
			dpIdx++;
			dp[dpIdx] = cable[idx].second;
		}
		else
		{
			int val = Search(1, dpIdx, cable[idx].second);
			dp[val - 1] = cable[idx].second;
		}
		idx++;
	}

	cout << n - dpIdx << "\n";

	return 0;
}