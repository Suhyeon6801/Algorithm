#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	long long sum = arr[0];

	if (sum != 1)
	{
		cout << "1\n";
	}
	else
	{
		for (int i = 1; i < N; i++)
		{
			if (sum + 1 < arr[i])	break;
			sum += arr[i];
		}

		cout << sum + 1 << "\n";
	}

	return 0;
}