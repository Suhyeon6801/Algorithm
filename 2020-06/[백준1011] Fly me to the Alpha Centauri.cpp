#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int tc=1; tc<=T; tc++)
	{
		long long x, y, dist, k;
		cin >> x >> y;

		dist = y - x;
		k = sqrt(dist);

		if (dist == 1)	cout << "1\n";
		else if (dist == 2)	cout << "2\n";
		else if (dist == 3)	cout << "3\n";
		else
		{
			if (dist == k * k)
			{
				cout << 2 * k - 1 << "\n";
			}
			else if (dist > k*k&&dist <= k * k + k)
			{
				cout << 2 * k << "\n";
			}
			else
			{
				cout << 2 * k + 1 << "\n";
			}
		}
	}

	return 0;
}