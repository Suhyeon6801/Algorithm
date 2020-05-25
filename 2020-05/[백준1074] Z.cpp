#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int cnt;

void recu(int size, int y, int x)
{
	if (size == 2)
	{
		if (r == y && x == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;

		if (r == y && x + 1 == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;

		if (r == y + 1 && x == c)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;

		if (r == y + 1 && c == x + 1)
		{
			cout << cnt << "\n";
			return;
		}
		cnt++;

		return;
	}

	recu(size / 2, y, x);
	recu(size / 2, y, x + size / 2);
	recu(size / 2, y + size / 2, x);
	recu(size / 2, y + size / 2, x + size / 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;

	int size = pow(2, N);

	recu(size, 0, 0);
	
	return 0;
}