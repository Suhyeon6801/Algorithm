#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int check[30];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int getMax = -1;
	int cnt = 0;
	char answer;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			check[str[i] - 'A']++;
		else
			check[str[i] - 'a']++;
	}

	for (int i = 0; i < 30; i++)
	{
		if (check[i] != 0)
		{
			getMax = max(check[i], getMax);
		}
	}

	for (int i = 0; i < 30; i++)
	{
		if (getMax == check[i])
		{
			cnt++;
			answer = i + 'A';
		}
	}

	if (cnt > 1)	cout << "?\n";
	else
		cout << answer << "\n";

	
	return 0;
}