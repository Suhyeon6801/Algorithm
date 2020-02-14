#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 210;
int arr[MAX];
int dp[MAX];

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

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int dpIdx = 1;
	int idx = 2;
	dp[dpIdx] = arr[1];

	while (idx <= N)
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

	cout << N-dpIdx << "\n";

	return 0;
}