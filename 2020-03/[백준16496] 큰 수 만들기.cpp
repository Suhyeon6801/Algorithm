#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool comp(string s1, string s2)
{
	if (s1 == s2)	return false;

	string temp1 = s1 + s2;
	string temp2 = s2 + s1;

	if (temp1 > temp2)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string num;
	cin >> N;

	vector<string> v;
	bool flag = false;
	string ans;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num != "0")	
			flag = true;

		v.push_back(num);
	}

	if (!flag)	cout << "0\n";
	else
	{
		sort(v.begin(), v.end(), comp);

		for (int i = 0; i < v.size(); i++)
			ans += v[i];

		cout << ans << "\n";
	}

	return 0;
}