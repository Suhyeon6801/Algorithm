#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 40010;
int port[MAX];
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
		cin >> port[i];

	int dpIdx = 1;
	int idx = 2;
	dp[1] = port[1];

	while (idx <= n)
	{
		if (dp[dpIdx] < port[idx])
		{
			dp[++dpIdx] = port[idx];
		}
		else
		{
			int val = Search(1, dpIdx, port[idx]);
			dp[val - 1] = port[idx];
		}
		idx++;
	}
	cout << dpIdx << "\n";

	return 0;
}