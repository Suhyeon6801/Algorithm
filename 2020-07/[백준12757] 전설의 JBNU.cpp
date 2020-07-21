//https://github.com/ytw0728/BOJ/blob/master/12757.cpp 참조
//key 찾는거 -> lower, upper_bound 이용!!
#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int N, M, K;
map<int, int> mp;

void update(int key, int val)
{
	if (mp.find(key) != mp.end())
	{
		mp[key] = val;
	}
	else
	{
		auto end = mp.end();
		auto low = mp.lower_bound(key);
		auto high = mp.upper_bound(key);
		low--;

		if ((low == end || low->first<key-K) && (high == end || high->first>key+K))	return;
		else if (low == end)
		{
			if (high->first < key + K)
				mp[high->first] = val;
		}
		else if (high == end)
		{
			if (low->first > key - K)
				mp[low->first] = val;
		}
		else
		{
			if (low == high)	mp[low->first] = val;
			else if (abs(low->first - key) > abs(high->first - key))	mp[high->first] = val;
			else if (abs(low->first - key) < abs(high->first - key))	mp[low->first] = val;
		}
	}
}

void find_and_print(int key)
{
	if (mp.find(key) != mp.end())
		cout << mp[key] << "\n";
	else
	{
		auto end = mp.end();
		auto low = mp.lower_bound(key);
		auto high = mp.upper_bound(key);
		low--;

		if ((low == end || low->first < key - K) && (high == end || high->first > key + K)) cout << "-1\n";
		else if (low == end)
		{
			if (high->first < key + K)
				cout << mp[high->first] << "\n";
		}
		else if (high == end)
		{
			if (low->first > key - K)
				cout << mp[low->first] << "\n";
		}
		else
		{
			if (low == high)	cout << mp[low->first] << "\n";
			else if (abs(low->first - key) > abs(high->first - key))	cout << mp[high->first] << "\n";
			else if (abs(low->first - key) < abs(high->first - key))	cout << mp[low->first] << "\n";
			else
				cout << "?\n";
		}
	}
}

void print(int i)
{
	cout << "현재" <<i<<"번째 진행 중 map상황\n";
	for (auto it = mp.begin(); it != mp.end(); it++)
		cout << it->first << " " << it->second << "\n";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int key, value, cmd;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> key >> value;
		mp[key] = value;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> cmd;
		if (cmd == 1)//추가
		{
			cin >> key >> value;
			mp[key] = value;
		}
		else if (cmd == 2)//수정
		{
			cin >> key >> value;
			update(key, value);
		}
		else//찾고 출력
		{
			cin >> key;
			find_and_print(key);
		}

		//print(i + 1);
	}

	return 0;
}