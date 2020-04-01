#include <iostream>
#include <map>
#include <string>
#include <cstring>
using namespace std;

//배열 사이즈 2배 주의 -> 이름 2개씩 받음.
int p[200010];//부모
int num[200010];//집합의 크기

int find(int x)
{
	if (p[x] == x)
		return x;
	else
		return find(p[x]);
}

int merge(int x, int y)
{
	int px = find(x);
	int py = find(y);

	if (px != py)
	{
		p[px] = py;
		num[py] += num[px];
		num[px] = 1;
	}
	
	return num[py];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase; 
	for (int tc = 1; tc <= testcase; tc++)
	{
		int F;
		string name1, name2;
		map<string, int> mp;
		int idx = 1;

		cin >> F;

		for (int i = 0; i <= 2 * F; i++)
		{
			p[i] = i;
			num[i] = 1;
		}

		for (int i = 0; i < F; i++)
		{
			cin >> name1 >> name2;

			if (mp.count(name1) == 0)
				mp[name1] = idx++;
			if (mp.count(name2) == 0)
				mp[name2] = idx++;

			cout << merge(mp[name1], mp[name2]) << "\n";
		}
	}

	return 0;
}