#include <iostream>
#include <algorithm>
using namespace std;

long long f[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 100; i++)
		f[i] = f[i - 1] + f[i - 2];

	int N;
	cin >> N;

	cout << f[N] * 2 + f[N + 1] * 2;

	return 0;
}