#include <iostream>
using namespace std;

int getGCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return getGCD(b, a%b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		int N;
		long long sum = 0;
		int arr[110] = { 0, };
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				sum += getGCD(arr[i], arr[j]);
			}
		}

		cout << sum << "\n";
	}
	
	return 0;
}