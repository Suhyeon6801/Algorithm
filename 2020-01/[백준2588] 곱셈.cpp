#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int num;
	string str;

	cin >> num >> str;

	int len = str.length();
	int ret = 1;
	int sum = 0;
	int idx = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		ret = 1;
		ret = (str[i] - '0')*num;

		cout << ret << "\n";

		sum += ret * (pow(10, idx));
		idx++;
	}
	cout << sum << "\n";

	return 0;
}