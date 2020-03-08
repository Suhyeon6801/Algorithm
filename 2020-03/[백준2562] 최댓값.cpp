#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int getMax = -1;
	int idx = 0;
	int n;
	for (int i = 1; i <= 9; i++)
	{
		cin >> n;

		if (n > getMax)
		{
			getMax = n;
			idx = i;
		}
	}

	cout << getMax << "\n";
	cout << idx << "\n";

	return 0;
}