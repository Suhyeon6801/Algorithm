#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int sum = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		sum += (s[i] - '0');

		if (s[i] - '0' == 0)	flag = true;
	}

	if (sum % 3 != 0 || !flag)
	{
		cout << "-1\n";
	}
	else
	{
		sort(s.begin(), s.end(), comp);
		cout << s << "\n";
	}
	
	return 0;
}