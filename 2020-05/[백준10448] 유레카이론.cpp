#include <iostream>
using namespace std;

int arr[50];

bool check(int x)
{
	for (int i = 1; i <= 45; i++)
	{
		for (int j = 1; j <= 45; j++)
		{
			for (int k = 1; k <= 45; k++)
			{
				if (arr[i] + arr[j] + arr[k] == x)
					return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 45; i++)
	{
		int sum = 0;
		for (int j = 1; j <= i; j++)
		{
			sum += j;
		}
		arr[i] = (sum + (sum + 1)) / 2;
	}

	int T, K;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> K;

		if (check(K))
			cout << "1\n";
		else
			cout << "0\n";
	}


	return 0;
}