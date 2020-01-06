#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> k;

		if (binary_search(arr,arr+n,k))
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}

	return 0;
}