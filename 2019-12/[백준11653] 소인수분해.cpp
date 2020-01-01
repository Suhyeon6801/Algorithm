#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10000010;
int arr[MAX] = { 0 };
int prime[MAX] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int idx = 0;

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		for (int j = i * i; j <= n; j+=i)
		{
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != 0)	prime[idx++] = i;
	}


	int j = 0;
	while (1)
	{
		if (n == 1)	break;

		if (n%prime[j] == 0)
		{
			cout << prime[j] << "\n";
			n /= prime[j];
		}
		else
		{
			j++;
		}
	}


	
	return 0;
}