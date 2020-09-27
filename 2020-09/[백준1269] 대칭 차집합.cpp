#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<int> s;
	map<int, int> mp;
	int A, B, n, cnt = 0;
	cin >> A >> B;

	for (int i = 0; i < A; i++)
	{
		cin >> n;
		s.insert(n);
		mp[n]++;
	}

	for (int i = 0; i < B; i++)
	{
		cin >> n;
		s.insert(n);

		if (mp.find(n) != mp.end())	cnt++;
		else	mp[n]++;
	}

	cout << s.size() - cnt << "\n";

	return 0;
}