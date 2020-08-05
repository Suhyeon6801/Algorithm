#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;
string str[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	string temp = "";
	cin >> R >> C;

	for (int i = 0; i < R; i++)
		cin >> str[i];

	//중복이 되는 순간을 찾으면 됨! -> 이분탐색으로 찾는다
	int start = 0, end = R, mid = 0;

	while (start + 1 < end)
	{
		mid = (start + end) / 2;
		bool check = true;

		for (int j = 0; j < C; j++)
		{
			temp = "";
			for (int i = mid; i < R; i++)
			{
				temp += str[i][j];
			}

			if (mp.count(temp) > 0)
			{
				check = false;
				break;
			}
			else
				mp[temp]++;
		}

		if (!check)
			end = mid;
		else
			start = mid;

		mp.clear();
	}

	cout << start << "\n";
	return 0;
}