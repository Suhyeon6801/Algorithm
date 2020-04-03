#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[100010];
int N, M;

bool check(long long int x)
{
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += x / arr[i];
	}

	if (sum >= M)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int getMax = -1;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		getMax = max(arr[i], getMax);
	}

	long long int start = 1;
	long long int end = getMax * M;
	long long int mid;

	while (start + 1 < end)
	{
		mid = (start + end) / 2;

		if (check(mid))
			end = mid;
		else
			start = mid;
	}

	cout << end << "\n";

	return 0;
}