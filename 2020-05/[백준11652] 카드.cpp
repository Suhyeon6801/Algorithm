#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<long long int, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long int num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		mp[num]++;
	}

	int max_cnt = 0;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		max_cnt = max(max_cnt, it->second);
	}

	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		if (max_cnt == it->second)
		{
			cout << it->first << "\n";
			break;
		}
	}
	
	return 0;
}