#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> mp1;
map<int, int> mp2;
vector<pair<int, int>> v;

bool comp(pair<int, int>p1, pair<int, int> p2)
{
	return p1.second > p2.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C, a;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> a;

		if (mp1.count(a) == 0)
		{
			mp1[a] = i;
		}
		mp2[a]++;
	}

	for (auto it = mp2.begin(); it != mp2.end(); it++)
		v.push_back(*it);

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].second == v[j].second)
			{
				auto it = mp1.find(v[i].first);
				auto it2 = mp1.find(v[j].first);

				if (it->second > it2->second)
					swap(v[i], v[j]);
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].second; j++)
			cout << v[i].first << " ";
	}

	return 0;
}