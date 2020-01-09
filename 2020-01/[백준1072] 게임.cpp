#include <iostream>
using namespace std;

long long int  x, y, z;

bool check(long long int n)
{
	long long int m = ((y + n) * 100) / (x + n);

	if (m <= z)	return false;
	else	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> y;

	z = (y * 100) / x;

	//승률이 99이면 절대 100이 될 수 없음.
	if (z >= 99)
	{
		cout << "-1\n";
		return 0;
	}

	long long int start = 0;
	long long int end = 1000000000;
	long long int mid;

	while (start + 1 < end)
	{
		mid = (start + end) / 2;
		if (check(mid))
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}

	cout << end << "\n";

	return 0;
}