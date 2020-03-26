#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		multiset<int> s;//중복가능
		int k, n;
		char cmd;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			cin >> cmd >> n;

			if (cmd == 'I')
			{
				s.insert(n);
			}
			else if (cmd == 'D')
			{
				if (!s.empty())
				{
					if (n == 1)
					{
						auto it = s.end();
						it--;
						s.erase(it);
					}
					else
					{
						auto it = s.begin();
						s.erase(it);
					}
				}
			}
		}

		if (s.empty())	cout << "EMPTY\n";
		else
		{
			auto it = s.end();
			auto iter = s.begin();
			it--;
			cout << *it << " " << *iter << "\n";
		}
	}

	return 0;
}