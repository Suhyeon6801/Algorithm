#include <iostream>
using namespace std;

const int MAX = 1010;
int dp[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= MAX; i++)
		dp[i] = (dp[i - 1] +2*dp[i - 2])%10007;

	int n;
	cin >> n;
	cout << dp[n]<< "\n";

	return 0;
}