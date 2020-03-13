#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];
int sum[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == 0)
			sum[i] = arr[i];
		else
		{
			for (int j = 0; j <= i; j++)
				sum[i] += arr[j];
		}
		result += sum[i];
	}

	cout << result << "\n";

	return 0;
}