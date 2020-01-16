#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[2][1010][1010];
int card[1010];

int maxScore(bool turn, int left, int right)
{
	int &ret = dp[turn][left][right];
	if (ret != -1)
		return ret;
	
	if (left == right)
	{
		if (turn)
			return ret = card[left];
		else
			return 0;
	}

	if (turn)
	{
		ret = max(maxScore(false, left + 1, right) + card[left], maxScore(false, left, right - 1) + card[right]);
	}
	else
	{
		return ret = min(maxScore(true, left + 1, right), maxScore(true, left, right - 1));
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		memset(dp, -1, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> card[i];

		cout << maxScore(true, 0, n - 1) << "\n";

		/*for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}

	return 0;
}