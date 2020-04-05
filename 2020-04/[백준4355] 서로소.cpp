#include <iostream>
using namespace std;

long long Euler_phi(int n)
{
	//n소인수 분해
	long long temp = n;

	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)//약/배수 인 관계
		{
			while (n%i == 0)
			{
				n /= i;
			}
			temp -= temp / i;
		}
	}

	if (n > 1)
		temp -= temp / n;

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		cout << Euler_phi(n) << "\n";
	}
	
	return 0;
}