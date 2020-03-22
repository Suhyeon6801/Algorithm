#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		int idx;
		string str;

		cin >> idx >> str;

		str.erase(idx-1, 1);
		cout << str << "\n";
	}

	return 0;
}