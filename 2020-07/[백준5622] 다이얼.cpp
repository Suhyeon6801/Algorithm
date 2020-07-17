#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'C')	count += 3;
		else if (str[i] >= 'D'&&str[i] <= 'F')	count += 4;
		else if (str[i] >= 'G'&&str[i] <= 'I')	count += 5;
		else if (str[i] >= 'J'&&str[i] <= 'L')	count += 6;
		else if (str[i] >= 'M'&&str[i] <= 'O')	count += 7;
		else if (str[i] >= 'P'&&str[i] <= 'S')	count += 8;
		else if (str[i] >= 'T'&&str[i] <= 'V')	count += 9;
		else if (str[i] >= 'W'&&str[i] <= 'Z')	count += 10;
	}

	cout << count;
	
	return 0;
}