#include <iostream>
using namespace std;

const int MAX = 10001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int arr[MAX] = { 0 };
	int cnt = 0;
	int j, sum;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		j = i;
		sum = 0;
		while (j<n)
		{
			sum += arr[j];
			j++;

			if (sum == m)
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
}