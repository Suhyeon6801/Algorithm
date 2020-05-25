#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1500010;
int Ti[MAX];
int Pi[MAX];
int dp[MAX];//i번째까지 일한 날 최대 액수.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, result = -1;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Ti[i] >> Pi[i];

	//1. i번째까지 일한 경우, 2.i번째 까지 일 안한 경우
	for (int i = 1; i <= N +1; i++)
	{
		result = max(result, dp[i]);

		if (i + Ti[i] > N + 1)	continue;

		dp[i + Ti[i]] = max(result + Pi[i], dp[i + Ti[i]]);
	}
	
	cout << dp[N+1] << "\n";

	return 0;
}