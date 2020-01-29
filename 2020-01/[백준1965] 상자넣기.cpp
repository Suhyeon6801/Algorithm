#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];
int arr[1010];
int p[1010];

int Search(int start, int end, int target)
{
	int mid;
	while (start < end)
	{
		mid = (start + end) / 2;
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
		cin >> arr[i];

	int dpIdx = 1;
	int idx = 2;
	dp[1] = arr[1];
	p[1] = arr[1];

	while(idx <= n)
	{
		if (dp[dpIdx] < arr[idx])
		{
			dpIdx++;
			dp[dpIdx] = arr[idx];
			p[idx] = arr[idx];
		}
		else
		{
			int val = Search(1, dpIdx, arr[idx]);
			dp[val - 1] = arr[idx];
			p[idx] = arr[idx];
		}
		idx++;
	}
	cout << dpIdx << "\n";


	return 0;
}