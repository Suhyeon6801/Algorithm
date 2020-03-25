#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		int n;
		map<string, int> clothes;
		string name, type;

		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			cin >> name >> type;
			clothes[type]++;
		}

		int cnt = 1;
		for (auto it = clothes.begin(); it != clothes.end(); it++)
			cnt *= (it->second + 1);

		cout << cnt - 1 << "\n";//마지막 -1은 아무것도 안입은 경우
	}

	return 0;
}