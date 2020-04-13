#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		map<char, int> mp;
		bool flag = true;
		char cur = str[0];
		mp[cur]++;
		for (int j = 1; j < str.length(); j++)
		{
			if (str[j] != cur)
			{
				if (mp.count(str[j]) == 0)
				{
					cur = str[j];
					mp[str[j]]++;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}

		if (flag)	cnt++;
	}

	cout << cnt << "\n";
	return 0;
}