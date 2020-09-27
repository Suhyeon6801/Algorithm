#include <iostream>
using namespace std;

long long S;

bool check(long long mid)
{
	long long sum = ((mid + 1)*mid) / 2;
	if (sum > S)	return true;
	else	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;

	long long s = 1, e = S, m = 0;

	while (s + 1 < e)
	{
		m = (s + e) / 2;

		if (check(m))
			e = m;
		else
			s = m;
	}

	cout << s << "\n";

	return 0;
}