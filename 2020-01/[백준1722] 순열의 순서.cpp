#include <iostream>
using namespace std;
long long int Fact[30];
bool check[30] = { 0, };
int arr[30];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Fact[0] = 1;
	for (int i = 1; i <= 20; i++)
		Fact[i] = Fact[i - 1] * i;

	int n, cmd;
	long long int k;
	cin >> n;
	cin >> cmd;

	if (cmd == 1)
	{
		cin >> k;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (check[j])
				{
					continue;
				}

				if (k <= Fact[n - i])
				{
					cout << j << " ";
					check[j] = true;
					break;
				}
				else
				{
					k -= Fact[n - i];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
			{
				cout << i << " ";
			}
		}
	}
	else if (cmd == 2)
	{
		long long int result = 1;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++)
		{
			check[arr[i]] = true;
			for (int j = 1; j < arr[i]; j++)
			{
				if (!check[j])
				{
					result += Fact[n - i];
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}