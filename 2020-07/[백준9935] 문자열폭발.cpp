#include <iostream>
#include <string>
using namespace std;

const string NotLeft = "FRULA";
char temp[1000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, str2;
	int idx = 0;
	cin >> str >> str2;

	for (int i = 0; i < str.length(); i++)
	{
		temp[idx++] = str[i];

		if (temp[idx - 1] == str2[str2.length() - 1])
		{
			if (idx - str2.length() < 0)
				continue;

			bool flag = true;
			for (int j = 0; j < str2.length(); j++)
			{
				if (temp[idx - j - 1] != str2[str2.length() - j - 1])
				{
					flag = false;
					break;
				}
			}

			if (flag)
				idx -= str2.length();
		}
	}

	if (idx == 0)
		cout << NotLeft << "\n";
	else
	{
		for (int i = 0; i < idx; i++)
			cout << temp[i];
	}
	return 0;
}