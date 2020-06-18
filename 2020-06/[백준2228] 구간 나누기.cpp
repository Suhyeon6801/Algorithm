#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 110;
const int MIN_INF = -32768 * 100;
int dp[MAX][MAX/2];//n개의 원소를 m개 구간으로 나눴을 때 최댓값.
int arr[MAX];

int solve(int N, int M)
{
	if (M == 0)	return 0;
	if (N < 0)	return MIN_INF;
	
	int &ret = dp[N][M];
	if (ret != -1)	return dp[N][M];

	int sum = 0;
	dp[N][M] = solve(N - 1, M);//N번째 인덱스가 포함되지 않는 경우 -> N-1번째값.

	//N번째 인덱스를 포함하면.
	for (int i = N; i > 0; i--)
	{
		sum += arr[i];//i부터 N까지 구간의 합 구하기.

		int temp = solve(i - 2, M - 1) + sum;//포함 안되는 범위에서 M-1개 구간의 합.
		if (temp > dp[N][M])
			dp[N][M] = temp;
	}
	return dp[N][M];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	//1. N번째 구간을 선택했을 때
	//2. N번째 구간을 선택하지 않았을 때.

	memset(dp, -1, sizeof(dp));
	cout << solve(N, M) << "\n";

	return 0;
}