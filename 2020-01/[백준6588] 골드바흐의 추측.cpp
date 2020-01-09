#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int MAX = 1000001;
int prime[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		for (int j = i*i; j <= MAX; j+=i)
		{
			prime[j] = 1;
		}
	}
	string Error = "Goldbach's conjecture is wrong.\n";

	int n;
	while (1)
	{
		cin >> n;

		if (n == 0)	break;

		//int idx = 2;
		bool flag = false;
		for (int i = 2; i< n; i++)
		{
			if (prime[i] == 0 && prime[n - i] == 0)
			{
				cout << n << " = " << i << " + " << n - i << "\n";
				flag = true;
				break;
			}
		}
		if (!flag)	cout << Error;
	}

	return 0;
}