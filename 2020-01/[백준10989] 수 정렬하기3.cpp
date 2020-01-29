#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int getMax = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		getMax = max(getMax, m);
		arr[m]++;
	}
	//cout << arr.size() << "\n";

	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		//cout << it->first << " " << it->second << "\n";
		for (int i = 0; i < it->second; i++)
			cout << it->first << "\n";
	}

	return 0;
}