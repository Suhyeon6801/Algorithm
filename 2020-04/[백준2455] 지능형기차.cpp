#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cur;
	int getMax = -1;
	int p1, p2;
	for (int i = 0; i < 4; i++)
	{
		cin >> p1 >> p2;

		if (i == 0)
			cur = p2;
		else
			cur = cur - p1 + p2;

		if (getMax < cur)
			getMax = cur;
	}

	cout << getMax << "\n";


	return 0;
}