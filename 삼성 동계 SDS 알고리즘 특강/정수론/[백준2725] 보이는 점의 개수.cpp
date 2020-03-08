#include <iostream>
using namespace std;

int arr[1010] = { 0, };
int gcd(int a, int b)
{
	if (b == 0)	return a;
	else
		return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= 1000; i++)
	{
		int count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (gcd(i, j) == 1)	count++;
		}
		arr[i] += arr[i - 1] + count;
	}

	int c, n;
	cin >> c;
	for (int tc = 0; tc < c; tc++)
	{
		cin >> n;
		cout << arr[n] * 2 + 1 +2 << "\n";
	}

	return 0;
}