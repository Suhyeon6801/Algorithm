#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000003;
int dp[1010][1010];//i개색 중 j개를 선택하는 경우 -> 1.현재 색 선택안하는 경우, 2. 선택하는 경우

int f(int i, int j)
{
	if (i<=0 || j>i/2)	return 0;
	if (j == 1)	return i;

	int &ret = dp[i][j];
	if (ret != -1)	return ret;

	return dp[i][j] = (f(i-2,j-1)+f(i-1,j)) % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	memset(dp, -1, sizeof(dp));

	cout << f(N,K) << "\n";
	
	return 0;
}