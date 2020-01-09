#include <iostream>
using namespace std;

long long int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	long long int start = 0, end = 0, sum = 0;
	long long int getMin = 100001;

	while (end <= start && start <= n)
	{
		if (sum < s)
		{
			sum += arr[start];
			start++;
		}
		else if (sum >= s)
		{
			int len = start - end;
			if (getMin > len)	getMin = len;
			sum -= arr[end];
			end++;
		}
		/*	else if (sum == s)
		{
		int len = start - end;
		if (getMin > len)	getMin = len;
		sum += arr[start];
		start++;
		}*/
	}

	if (getMin == 100001)	cout << "0\n";
	else	cout << getMin << "\n";

	return 0;
}