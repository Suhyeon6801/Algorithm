#include <iostream>
using namespace std;

const int MAX = 123456 * 2;
int prime[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	prime[1] = 1;
	for (int i = 2; i*i <= MAX; i++)
	{
		for (int j = i * i; j <= MAX; j += i)
			prime[j] = 1;
	}

	int n;

	while (1)
	{
		int cnt = 0;
		cin >> n;

		if (n == 0)	break;

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (prime[i] == 0)
				cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}