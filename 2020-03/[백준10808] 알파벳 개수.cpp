#include <iostream>
#include <string>
using namespace std;

int alpahbet[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		int temp = str[i] - 'a';
		alpahbet[temp]++;
	}

	for (int i = 0; i < 26; i++)
		cout << alpahbet[i] << " ";

	return 0;
}