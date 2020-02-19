#include <iostream>
using namespace std;

int arr[1010];
int dp[1010];

int Search(int s, int e, int t)
{
	int m;
	while (s < e)
	{
		m = (s + e) / 2;
		if (dp[m] > t)
			s = m + 1;
		else
			e = m;
	}
	return e + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	int dpIdx = 1;
	int idx = 2;
	dp[1] = arr[1];

	while (idx <= N)
	{
		if (dp[dpIdx] > arr[idx])
		{
			dp[++dpIdx] = arr[idx];
		}
		else
		{
			int val = Search(1, dpIdx, arr[idx]);
			dp[val - 1] = arr[idx];
		}
		idx++;
	}
	cout << dpIdx << "\n";
	/*for (int i = 1; i <= dpIdx; i++)
		cout << dp[i] << " ";*/

	return 0;
}