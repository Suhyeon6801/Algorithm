#include <iostream>
using namespace std;

int getGCD(int x, int y)
{
	if (y == 0)
		return x;
	else
		return getGCD(y, x%y);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, GCD, LCM;
	cin >> a >> b;

	GCD = getGCD(a, b);
	cout << GCD << "\n";
	LCM = GCD * (a / GCD)*(b / GCD);
	cout << LCM << "\n";

	return 0;
}