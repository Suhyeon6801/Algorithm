#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int arr[100];
	int n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= 90; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cin >> n;

	cout << arr[n] << "\n";
	
}