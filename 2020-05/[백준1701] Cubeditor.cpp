#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getMax(string p)
{
	vector<int> table(p.size(), 0);
	int j = 0;
	int ret = 0;

	for (int i = 1; i < p.size(); i++)
	{
		while (j > 0 && p[i] != p[j])
			j = table[j - 1];

		if (p[i] == p[j])
		{
			ret=max(ret,table[i] = ++j);
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		string temp = str.substr(i, str.length());
		result = max(result, getMax(temp));
	}

	cout << result << "\n";

	return 0;
}