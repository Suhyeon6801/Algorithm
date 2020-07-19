#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	string str;
	cin >> T;

	for(int tc=0; tc<T; tc++)
	{
		if(tc==0)
			cin.ignore();

		getline(cin, str);
		
		string temp = "";
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				reverse(temp.begin(), temp.end());
				cout << temp << " ";
				temp = "";
			}
			else if (i == str.length() - 1)
			{
				temp += str[i];
				reverse(temp.begin(), temp.end());
				cout << temp << "\n";
			}
			else
				temp += str[i];
		}
	}
	
	return 0;
}