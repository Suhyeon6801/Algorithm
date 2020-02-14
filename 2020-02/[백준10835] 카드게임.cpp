#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 2010;
int dp[MAX][MAX];
int leftCard[MAX];
int rightCard[MAX];
int N;

int func(int left, int right)
{
	if (left > N || right > N)	return 0;

	int& ret = dp[left][right];
	if (ret != -1)	return ret;

	ret = max(func(left + 1, right), func(left + 1, right + 1));
	if (leftCard[left] > rightCard[right])
	{
		ret = max(ret, func(left, right + 1) + rightCard[right]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> leftCard[i];

	for (int i = 0; i < N; i++)
		cin >> rightCard[i];

	memset(dp, -1, sizeof(dp));

	cout << func(0, 0);
	
	return 0;
}