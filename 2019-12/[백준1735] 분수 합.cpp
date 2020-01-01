#include <iostream>
using namespace std;

long long int getGCD(long long int x, long long int y)
{
	long long int a = x;
	long long int b = y;
	long long int r, gcd;

	while (1)
	{
		r = a % b;

		if (r == 0)
		{
			gcd = b;
			break;
		}

		a = b;
		b = r;
	}

	return gcd;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int a, b, c, d;
	long long int res1, res2;
	cin >> a >> b >> c >> d;

	long long int lcm = getGCD(b, d)*b*d;

	res1 = a * (lcm / b) + c * (lcm / d);
	res2 = lcm;

	if (getGCD(res1, res2) != 1)
	{
		long long int gcd = getGCD(res1, res2);

		cout << res1 / gcd << " " << res2 / gcd << "\n";
	}
	else
	{
		cout << res1 << " " << res2 << "\n";
	}

	return 0;
}