#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 501;
int arr[MAX][2];
int dp[MAX][MAX] = { 0, };//i->j까지의 행렬 곱의 최소 연산 횟수

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];


	//초기화, 인접한 행렬들은 미리 계산한다.
	for (int i = 1; i < n; i++)
	{
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int m = 2; m <= n; m++)
	{
		for (int i = 1; i <= n - m; i++)
		{
			int j = i + m;
			for (int k = i; k < j; k++)
			{
				int temp = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				if (dp[i][j] == 0 || dp[i][j] > temp)
					dp[i][j] = temp;
			
		}
	}
	cout << dp[1][n] << "\n";

	return 0;
}