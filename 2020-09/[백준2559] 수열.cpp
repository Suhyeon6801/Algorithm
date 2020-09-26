#include <iostream>
#include <algorithm>
using namespace std;

const int MIN_INF = -987654321;
int arr[100010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left = 0, right = 0, sum = 0, size = 0, getMax = MIN_INF;

	while (left <= N)
	{
		if (size >= K)
		{
			if (size == K)	getMax = max(sum, getMax);
			size--;
			sum -= arr[right++];
		}
		else
		{
			size++;
			sum += arr[left++];
		}
	}

	cout << getMax << "\n";

	return 0;
}