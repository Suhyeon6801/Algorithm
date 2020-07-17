#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> mp;
vector<pair<string, int>> v;

bool comp(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second)
		return p1.first < p2.first;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string title;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> title;
		mp[title]++;
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
		v.push_back(*it);

	sort(v.begin(), v.end(), comp);

	cout << v[0].first << "\n";

	return 0;
}