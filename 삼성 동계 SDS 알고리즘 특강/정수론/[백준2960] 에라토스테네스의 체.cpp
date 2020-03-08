#include <iostream>
using namespace std;

const int MAX = 1010;

int num[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k;
	int cnt = 0;
	int p;
	cin >> n >> k;

	for (int i = 2; i <= n; i++)
	{
		num[i] = i;
	}

	while (cnt<k)
	{
		for (int i = 2; i <= n; i++)
		{
			if (num[i] != 0)
			{
				p = i;
				break;
			}
		}

		for (int i = 1; i <= n; i++)
		{
			int t = i * p;
			if (t > n)	break;

			if (num[t] != 0)
			{
				num[t] = 0;
				cnt++;
			}

			if (cnt == k)
			{
				cout << t << "\n";
				return 0;
			}
		}
	}

	return 0;
}