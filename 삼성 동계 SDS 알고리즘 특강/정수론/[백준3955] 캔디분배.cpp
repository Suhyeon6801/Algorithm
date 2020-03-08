#include <iostream>
using namespace std;

int gcd(int x, int y)
{
	int a = x;
	int b = y;
	int r, gcd;

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

long func(int k, int c)
{
	long q, r, r1, r2, s, s1, s2, t, t1, t2;
	r1 = k;
	r2 = c;
	s1 = 1;
	s2 = 0;
	t1 = 0;
	t2 = 1;

	while (r2 != 0)
	{
		q = r1 / r2;
		r = r1 - r2 * q;
		s = s1 - s2 * q;
		t = t1 - t2 * q;
		r1 = r2;
		r2 = r;
		s1 = s2;
		s2 = s;
		t1 = t2;
		t2 = t;
	}

	if (r1 != 1)	return 1000000001;

	return (t1 + k) % k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int tc = 0; tc < testcase; tc++)
	{
		int k, c;
		cin >> k >> c;

		//cout << gcd(10, 7) << endl;

		if (gcd(k, c) != 1)
		{
			cout << "IMPOSSIBLE\n";
		}
		else
		{
			long result;
			if (c == 1)	result = k + 1;
			else if (k == 1)	result = 1;
			else
				result = func(k, c);

			if (result > 1000000000)	cout << "IMPOSSIBLE\n";
			else
				cout << result << "\n";
		}
	}

	return 0;
}