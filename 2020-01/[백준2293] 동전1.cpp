#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[100010];
int arr[110];
int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 1;//자기자식만큼 가치를 만들어내는 경우 인덱스0이 되니 1로 초기화

	for (int i = 1; i <= n; i++)
	{
		//arr[i]에 대해 k까지 돈다, 그 다음 코인에 대해 k까지 돈다.
		for (int j = arr[i]; j <= k; j++)
		{
			dp[j] += dp[j - arr[i]];
		}
	}

	//for (int j = 1; j <= k; j++)
	//	cout << dp[j] << " ";
	//cout << "\n";
	cout << dp[k];

	return 0;
}