#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<string, int> tree;
	string name;
	int cnt = 0;

	while (getline(cin, name))
	{
		tree[name]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto i : tree)
	{
		cout << i.first << " "<< (double)i.second / cnt * 100 << endl;
	}

	return 0;;
}