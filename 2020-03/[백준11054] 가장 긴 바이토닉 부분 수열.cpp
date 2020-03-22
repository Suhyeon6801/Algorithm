#include <iostream>
using namespace std;

const int MAX = 1010;
int arr[MAX]; 
int dp1[MAX];
int dp2[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	//가장 긴 증가하는 부분 수열
	for (int i = 1; i <= N; i++)
	{
		dp1[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (arr[j] < arr[i] && dp1[i] < dp1[j] + 1)
			{
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	//가장 작은 증가하는 부분 수열
	for (int i = N; i >= 1; i--)
	{
		dp2[i] = 1;
		for (int j = N; j >= i; j--)
		{
			if (arr[j] < arr[i] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
	}

	//증가하는 부분 수열크기 + 감소하는 부분수열 크기 - 1(-1은 중복제거)
	int cnt = 0;
	for (int i = 0; i <= N; i++)
	{
		if (cnt < dp1[i] + dp2[i] - 1)	cnt = dp1[i] + dp2[i] - 1;
	}

	cout << cnt << "\n";

	return 0;
}