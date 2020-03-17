#include <iostream>
using namespace std;

long long int N, K;

bool check(long long int x)
{
	long long int sum = 0;
	for (long long int i = 1; i <= N; i++)
	{
		if (x / i >= N)	sum += N;
		else
			sum += x / i;
	}

	if (sum >= K)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	long long int start = 0;
	long long int end = N * N;

	while (start + 1 < end)
	{
		long long int mid = (start + end) / 2;
		if (check(mid))
			end = mid;
		else
			start = mid;
	}

	cout << end << "\n";

	return 0;
}