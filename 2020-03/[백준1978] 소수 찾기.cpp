#include <iostream>
#include <cmath>
using namespace std;

bool check(int x)
{
	if (x == 1 || x == 0)	return false;

	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	int m, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> m;

		if (check(m))
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}