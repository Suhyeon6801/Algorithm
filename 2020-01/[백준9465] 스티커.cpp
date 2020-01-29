#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[2][100010];
int dp[2][100010];//0/1번째에서 시작해서 i번째까지 왔을 때 최댓값, 0,1이 n번째 도달했을 때 최댓값
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[i][j];
			}
		}

		//1칸 뒤 대각선, 2칸 뒤 대각선고려
		dp[0][0] = dp[1][0] = 0;//2번째칸에서 오는 경우
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}

		cout << max(dp[0][n], dp[1][n]) << "\n";

	}

	return 0;
}