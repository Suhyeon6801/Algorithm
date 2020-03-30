#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp1[100010];//i번째 기준으로 왼쪽까지 최댓값
int dp2[100010];//i번째 기준으로 오른쪽까지의 최댓값
int dp[100010];
int arr[100010];
int getMax = -999999999;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp1[1] = arr[1];

	getMax = max(dp1[1], getMax);
	for (int i = 2; i <= N; i++)
	{
		dp1[i] = max(dp1[i - 1] + arr[i], arr[i]);
		getMax = max(dp1[i], getMax);
	}

	dp2[N] = arr[N];
	
	for (int i = N - 1; i >= 1; i--)
	{
		dp2[i] = arr[i];
		dp2[i] = max(dp2[i + 1] + arr[i], arr[i]);
	}

	for (int i = 2; i <= N - 1; i++)
	{
		getMax = max(getMax, dp1[i - 1] + dp2[i + 1]);
	}

	cout << getMax << "\n";

	
	return 0;
}