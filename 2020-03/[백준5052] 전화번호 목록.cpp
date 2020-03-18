#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		string str[10010];
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}

		sort(str, str + n);//문자열 길이 낮은 순으로 정렬

		bool flag = true;
		for (int i = 1; i < n; i++)
		{
			if (str[i].substr(0, str[i-1].length()) == str[i-1])
			{
				flag = false;
				break;
			}		
		}

		if (!flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}