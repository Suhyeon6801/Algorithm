//메모리 초과
//int = 4byte ->  chleo 300000 -> 4MB 넘음
//위에서 처리한건 다시 쓰일일이 없다.
//계산한거 위로 올려버림.

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int arr[MAX][3];
int dp[2][3] = { 0, };
int dp2[2][3] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	dp2[0][0] = arr[0][0];
	dp2[0][1] = arr[0][1];
	dp2[0][2] = arr[0][2];

	for (int i = 1; i < n; i++)
	{
		dp[1][0] = max(dp[0][0], dp[0][1]) + arr[i][0];
		dp[1][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + arr[i][1];
		dp[1][2] = max(dp[0][1], dp[0][2]) + arr[i][2];

		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];

		dp2[1][0] = min(dp2[0][0], dp2[0][1]) + arr[i][0];
		dp2[1][1] = min(dp2[0][0], min(dp2[0][1], dp2[0][2])) + arr[i][1];
		dp2[1][2] = min(dp2[0][1], dp2[0][2]) + arr[i][2];

		dp2[0][0] = dp2[1][0];
		dp2[0][1] = dp2[1][1];
		dp2[0][2] = dp2[1][2];

	}

	cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << " " << min(dp2[0][0], min(dp2[0][1], dp2[0][2])) << "\n";


	return 0;
}