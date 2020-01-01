#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 4000010;

int arr[MAX] = { 0, };
int prime[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n;
	long long int sum = 0;
	int idx = 0;
	int cnt = 0;
	cin >> n;

	//에라토스테네스의 체로 소수 찾기
	for (int i = 2; i <= sqrt(n); i++)
	{
		for (int j = i * i; j <= n; j += i)
		{
			arr[j] = 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == 0)
		{
			prime[idx++] = i;
		}
	}

	for (int i = 0; i < idx; i++)
	{
		sum = 0;
		for (int j = i; j < idx; j++)
		{
			sum += prime[j];

			if (sum > n)	break;
			if (sum == n)
			{
				cnt++;
				break;
			}
		}
	}
	cout << cnt << "\n";


	
	return 0;
}