#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}


	return 0;
}