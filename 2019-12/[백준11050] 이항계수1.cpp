#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[20][20] = { 0, };
	int n, k;
	cin >> n >> k;

	arr[1][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i <= 10; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cout << arr[n][k] << "\n";
	
	return 0;
}