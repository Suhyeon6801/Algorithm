#include <iostream>
using namespace std;

int getMin(int a, int b)
{
	if (a < b)	return a;
	else
		return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int S, K, H;
	int sum = 0;
	int low = 101;

	cin >> S >> K >> H;

	sum = S + K + H;

	if (sum >= 100)
		cout << "OK\n";
	else
	{
		low = getMin(S, getMin(K, H));

		if (low == S)
			cout << "Soongsil\n";
		else if (low == K)
			cout << "Korea\n";
		else
			cout << "Hanyang\n";
	}
	
	return 0;
}