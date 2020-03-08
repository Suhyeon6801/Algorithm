#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	while (1)
	{
		cin >> a >> b;

		if (a == 0 && b == 0)	break;

		cout << a + b << "\n";
	}

	return 0;
}