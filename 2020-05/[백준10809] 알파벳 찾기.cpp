#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<char, int>mp;
	string alpha = "abcdefghijklmnopqrstuvwxyz";

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (mp.count(str[i]) == 0)
			mp.insert(make_pair(str[i], i));
	}

	int idx = 0;
	auto it = mp.begin();
	while (it != mp.end())
	{
		if (it->first == alpha[idx])
		{
			cout << it->second << " ";
			idx++;
			it++;
		}
		else
		{
			cout << "-1 ";
			idx++;
		}
	}

	for (int i = idx; i < alpha.length(); i++)
		cout << "-1 ";

	return 0;
}