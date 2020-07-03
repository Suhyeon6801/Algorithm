#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string numbers[60];
bool check[10] = { 0, };
bool check2[10] = { 0, };
map<char, long long> mp;
vector<pair<char, long long>> v;
vector<pair<char, int>> v2;

bool comp(pair<char, long long> p1, pair<char, long long> p2)
{
	return p1.second > p2.second;
}

int find_number(char c)
{
	for (int i = 0; i < v2.size(); i++)
	{
		if (v2[i].first == c)
			return v2[i].second;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int N;
	long long sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		numbers[i] = str;

		int k = str.length() - 1;
		for (int j = 0; j < str.length(); j++)
		{
			char c = str[j];

			if (j == 0)
				check[c - 'A'] = true;

			auto it = mp.find(c);

			if (it == mp.end())
				mp.insert(make_pair(c, pow(10, k)));
			else
			{
				long long index = it->second + pow(10, k);
				mp.erase(it);
				mp.insert(make_pair(c, index));
			}
			k--;
		}
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
		v.push_back(*it);

	sort(v.begin(), v.end(), comp);

	int b = 9;

	if (v.size() == 10)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (!check[v[i].first - 'A'] || (check[v[i].first - 'A'] && b != 0))
			{
				v2.push_back({ v[i].first, b-- });
			}
			else
			{
				int idx = 0;

				for (int j = v2.size() - 1; j >= 0; j--)
				{
					if (!check[v2[j].first - 'A'])
					{
						idx = v2[j].second;
						v2[j].second = 0;
						break;
					}
				}

				v2.push_back({ v[i].first, idx });
			}
		}

		for (int i = v2.size()-1; i >0; i--)
		{
			if (check[v2[i].first - 'A'] && check[v2[i-1].first-'A'])
			{
				if (v2[i].second > v2[i - 1].second)
				{
					swap(v2[i].second, v2[i - 1].second);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < v.size(); i++)
			v2.push_back({ v[i].first, b-- });
	}

	for (int i = 0; i < N; i++)
	{
		string temp = numbers[i];
		string result = "";

		for (int j = 0; j < temp.length(); j++)
		{
			result += (find_number(temp[j]) + '0');
		}
		sum += stoll(result);
	}

	cout << sum << "\n";

	return 0;
}