#include <iostream>
using namespace std;

const int MAX = 40010;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b)
{
	int g = gcd(a, b);
	return (a / g)*(b / g)*g;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int endYear = lcm(M, N);
		int result = -1;

		for (int i = x; i <= endYear; i += M)
		{
			int temp = (i % N == 0) ? N : i % N;

			if (temp == y)
			{
				result = i;
				break;
			}
		}

		cout << result << "\n";
	}

	return 0;
}