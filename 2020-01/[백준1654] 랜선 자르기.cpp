#include <iostream>
using namespace std;

int K, N;
long long arr[10010];

bool check(long long len)
{
	long long cnt = 0;
	for (int i = 0; i < K; i++)
	{
		cnt += arr[i] / len;
	}

	//cout << len << " " << cnt << "\n";
	if (cnt >= N)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long getMax = -1;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];

		if (getMax < arr[i])	getMax = arr[i];
	}

	long long start = 1;
	long long end = getMax;
	long long mid;

	if (check(end))
	{
		cout << end << "\n";
		return 0;
	}

	while (start + 1 < end)
	{
		mid = (start + end) / 2;
		if (check(mid))	start = mid;
		else
			end = mid;
	}

	cout << start;

	return 0;
}