#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= 2 * N; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j <= N; j++)
			{
				if (j % 2 == 1)
					cout << "*";
				else
					cout << " ";
			}
		}
		else
		{
			for (int j = 1; j <= N; j++)
			{
				if (j % 2 ==0)
					cout << "*";
				else
					cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}