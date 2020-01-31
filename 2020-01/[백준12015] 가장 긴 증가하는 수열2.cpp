#include <iostream>
using namespace std;

int arr[1000010];
int dp[1000010];

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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	int dpIdx = 1, idx = 2;

	while (idx <= n)
	{
		if (dp[dpIdx] < arr[idx])
		{
			dpIdx++;
			dp[dpIdx] = arr[idx];
		}
		else
		{
			int val = Search(1, dpIdx, arr[idx]);
			dp[val - 1] = arr[idx];
		}
		idx++;
	}
	cout << dpIdx;
	return 0;
}