#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int X;
	cin >> X;

	if (X == 64)
		cout << "1\n";
	else
	{
		int len = 64;
		int cnt = 0;
		while (X>0)
		{
			if (len > X)	len /= 2;
			else
			{
				X = X - len;
				cnt++;
			}
		}

		cout << cnt << "\n";
	}
	
	return 0;
}