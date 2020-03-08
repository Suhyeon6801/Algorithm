#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1000010;
int prime[MAX] = { 0, };
int arr[110];
int arr2[110];
vector<int> p;

//모든 수의 최대공약수 -> 모든 수에 공통적으로 존재하는 수 -> 소수를 최대한 고르게 분포
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		for (int j = i * i; j <= MAX; j+=i)
		{
			prime[j] = 1;
		}
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i] == 0)	p.push_back(i);
	}

	int n;
	int gcd = 1;
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < p.size(); i++)//소인수 분해 진행
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int temp = arr[j];
			arr2[j] = 0;
			while (temp%p[i]==0)
			{
				arr2[j]++;
				temp /= p[i];
			}
			sum += arr2[j];
		}
		for (int j = 0; j < sum / n; j++)//고르게 분포해야함.
		{
			gcd *= p[i];//나눠질 수 있는 횟수만큼 점수 누적
		}

		for (int j = 0; j < n; j++)
		{
			cnt += max(sum / n - arr2[j], 0);
		}
	}

	cout << gcd << " " << cnt << "\n";
	
	return 0;
}