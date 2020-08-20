#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, temp = "", result = "";
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '<')
		{
			int idx = i;
			while (s[idx] != '>')
			{
				temp += s[idx++];
			}
			temp += s[idx];
			i = idx;
			result += temp;
			temp = "";
		}
		else if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= '0'&&s[i] <= '9'))
		{
			temp += s[i];

			if (i == s.length() - 1 || s[i+1] == '<' || s[i+1]==' ')
			{
				reverse(temp.begin(), temp.end());
				result += temp;
				if (s[i + 1] == ' ')
					result += " ";
				temp = "";
			}
		}
	}

	cout << result << "\n";

	return 0;
}