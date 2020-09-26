#include <iostream>
using namespace std;

int K;

int recu(int x)
{
	if (x == 1)	return 1;
	else	return 2 * recu(x - 1) + 1;
}

void printOrder(int n, int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}

	printOrder(n - 1, from, to, by);
	cout << from << " " << to << "\n";
	printOrder(n - 1, by, from, to);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;

	cout << recu(K) << "\n";
	printOrder(K, 1, 2, 3);

	return 0;
}