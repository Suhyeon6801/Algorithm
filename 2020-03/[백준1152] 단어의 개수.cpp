#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	getline(cin, str);

	int cnt = 0;
	bool flag;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			flag = true;
		else if (flag)
		{
			flag = false;
			cnt++;
		}
	}

	cout << cnt << "\n";
	
	return 0;
}