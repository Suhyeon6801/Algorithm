#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, kim, lim;
	cin >> N >> kim >> lim;

	int round = 1;
	while (N > 0)
	{
		if ((kim + 1) / 2 == (lim + 1) / 2)	break;

		kim = (kim + 1) / 2;
		lim = (lim + 1) / 2;
		round++;
		N /= 2;
	}
	
	if (N == 0)	cout << "-1\n";
	else
		cout << round << "\n";

	return 0;
}