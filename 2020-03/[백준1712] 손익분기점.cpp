#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long a, b, c;
	cin >> a >> b >> c;

	long val = c - b;
	long cnt = 0;

	if (val <= 0)
		cout << "-1\n";
	else
	{
		cnt = a / val;
		cout << cnt + 1 << "\n";
	}

	return 0;
}