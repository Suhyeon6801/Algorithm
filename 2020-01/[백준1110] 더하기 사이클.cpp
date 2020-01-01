#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a = n / 10;
	int b = n % 10;
	int cnt = 0;

	while (1)
	{
		int c = a + b;

		a = b;
		b = c;

		if (b >= 10)	b %= 10;

		int d = a * 10 + b;

		if (d == n)	break;
		else
		{
			cnt++;
			a = d / 10;
			b = d % 10;
		}
	}

	cout << cnt+1 << "\n";

	return 0;
}
