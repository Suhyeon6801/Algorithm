#include <iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (cin >> n)
	{
		int temp = 1;
		int cnt = 0;
		while (1)
		{
			if (temp%n == 0)
			{
				cout << cnt + 1 << "\n";
				break;
			}
			cnt++;
			temp = temp%n;
			temp *= 10;
			temp += 1;
		}
	}

	return 0;
}