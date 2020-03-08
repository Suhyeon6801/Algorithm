#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[50] = { 0, };
	int a, cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> a;

		arr[a % 42]++;
	}

	for (int i = 0; i <= 41; i++)
	{
		if (arr[i] != 0)	cnt++;
	}

	cout << cnt << "\n";
	return 0;
}