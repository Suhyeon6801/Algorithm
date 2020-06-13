#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string str;
		cin >> str;

		int a = str[0]-'0', b = str[2]-'0';
		cout << a + b << "\n";
	}

	return 0;
}