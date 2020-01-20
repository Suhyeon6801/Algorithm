#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[2010];
long long dp[2010][2010];//현 상황에서 가져간 가장 왼쪽위치, 오른쪽 위치의 최댓값
int n;

long long JOI(int left, int right);
long long IOI(int left, int right);

long long Plus(int x)
{
	return (x + 1) % n;
}

long long Minus(int x)
{
	return (x + n - 1) % n;
}

long long JOI(int left, int right)
{
	//left-1과 right+1번째 중 더 큰값
	long long & ret = dp[left][right];
	if (ret != -1)	return ret;
	if (Plus(right) == left)	return ret = 0;
	long long temp1 = arr[Minus(left)] + IOI(Minus(left), right);
	long long temp2 = arr[Plus(right)] + IOI(left, Plus(right));

	ret = max(temp1, temp2);
	return ret;
}

long long IOI(int left, int right)
{
	//left-1번째, right+1번째가져갔을 때 최종적으로 더 큰 결과를 갖게 된는 쪽!
	if (Plus(right) == left)	return 0;
	if (arr[Minus(left)] > arr[Plus(right)])	return JOI(Minus(left), right);
	else
		return JOI(left, Plus(right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	long long getMax = -1;
	for (int i = 0; i < n; i++)
	{
		getMax = max(getMax, arr[i] + IOI(i, i));
	}
	cout << getMax << "\n";
	return 0;
}