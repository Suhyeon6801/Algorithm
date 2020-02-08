#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100010;
int p[MAX];
int dp[MAX];

int Search(int start, int end, int target)
{
	int mid;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (dp[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}

	return end + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	//cin >> testcase;
	while (cin >> testcase)
	{
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(p));

		for (int i = 1; i <= testcase; i++)
		{
			cin >> p[i];
		}

		int dpIdx = 1;
		int idx = 2;
		dp[1] = p[1];

		while (idx <= testcase)
		{
			if (dp[dpIdx] < p[idx])
			{
				dpIdx++;
				dp[dpIdx] = p[idx];
			}
			else
			{
				int val = Search(1, dpIdx, p[idx]);
				dp[val - 1] = p[idx];
			}
			idx++;
		}
		cout << dpIdx << "\n";
	}

	return 0;
}