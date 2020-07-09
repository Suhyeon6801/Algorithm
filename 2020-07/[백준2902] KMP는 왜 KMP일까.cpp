#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, result = "";
	cin >> str;

	result += str[0];
	int i = 1;
	while (i < str.length())
	{
		if (str[i] == '-')
		{
			result += str[i + 1];
			i++;
		}
		i++;
	}

	cout << result << "\n";

	return 0;
}