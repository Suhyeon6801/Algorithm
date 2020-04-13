#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int R, B;
	int L, W;
	cin >> R >> B;

	int total = R + B;

	for (int i = total; i >= 1; i--)
	{
		if (total%i == 0)
		{
			L = i;
			W = total / i;

			if ((L * 2 + (W - 2) * 2) == R)	break;
		}
	}

	cout << L << " " << W << "\n";

	return 0;
}