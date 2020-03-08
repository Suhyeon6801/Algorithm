#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[10] = { 0, };
	int a, b, c;
	int result, idx;
	cin >> a >> b >> c;

	result = a * b * c;

	while (result > 0)
	{
		idx = result % 10;
		arr[idx]++;
		result /= 10;
	}

	for (int i = 0; i <= 9; i++)
		cout << arr[i] << "\n";

	return 0;
}