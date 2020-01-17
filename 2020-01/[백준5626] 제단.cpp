#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 10005;
const long long Mod = 1000000007;
long long dp[2][MAX];//i번째 제단이 j번째 높이를 만드는 방법->메모리 초과로 현재경우 i와 바로 이전 경우 i-1번만 사용!
long long arr[MAX];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	//첫 입력이 불가능한 경우
	if (arr[1] < 1)
		dp[0][0] = 1;
	else
		dp[0][0] = 0;

	for (int i = 2; i <= n; i++)
	{
		fill_n(&dp[1][0], MAX, 0);
		if (arr[i] == -1)//모든경우
		{
			dp[1][0] = (dp[0][0] + dp[0][1]) % Mod;
			for (int j = 1; j <= MAX / 2; j++)
			{
				dp[1][j] = (dp[0][j - 1] + dp[0][j] + dp[0][j + 1]) % Mod;
			}
		}
		else if (arr[i] == 0)//높이에 대해서만 계산
		{
			dp[1][arr[i]] = (dp[0][arr[i]] + dp[0][arr[i] + 1]) % Mod;
		}
		else //높이에 대해서만 계산!
		{
			dp[1][arr[i]] = (dp[0][arr[i] - 1] + dp[0][arr[i]] + dp[0][arr[i] + 1]) % Mod;
		}

		swap(dp[0], dp[1]);
	}

	//for (int i = ; i <= 2; i++)
	//{
	//	for (int j = 0; j <= MAX / 2; j++)
	//	{
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << dp[0][0] << "\n";


	
	return 0;
}