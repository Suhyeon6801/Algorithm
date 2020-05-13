#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

map<string, bool, greater<string>>mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	string name, check;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> name >> check;

		if (check == "enter")
		{
			mp[name] = true;
		}
		else
			mp[name] = false;
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		if (it->second == true)
			cout << it->first << "\n";
	}

	return 0;
}