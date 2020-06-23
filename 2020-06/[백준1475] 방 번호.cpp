#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[10] = { 0, };
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		int temp = str[i] - '0';
		arr[temp]++;
	}

	int ans= 0;
	for (int i = 0; i < 10; i++)
	{
		if (i != 9 && i != 6)
			ans = max(ans, arr[i]);
	}

	ans = max((arr[6] + arr[9] + 1) / 2, ans);
	cout << ans << "\n";

	return 0;
}