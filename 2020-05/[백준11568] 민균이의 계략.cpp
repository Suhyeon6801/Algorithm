#include <iostream>
using namespace std;

const int MAX = 1010;
int arr[MAX];
int dp[MAX];

int Search(int left, int right, int target)
{
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (dp[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return right + 1;
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
			dp[++dpIdx] = arr[idx];
		else
		{
			int val = Search(1, dpIdx, arr[idx]);
			dp[val - 1] = arr[idx];
		}
		idx++;
	}

	cout << dpIdx << "\n";

	return 0;
}