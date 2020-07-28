#include <iostream>
#include <string>
using namespace std;

string make_all_upper(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')	continue;
		else
		{
			if (s[i] >= 'a'&&s[i] <= 'z')
				s[i] = s[i] - 'a' + 'A';
		}
	}

	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;

	while (1)
	{
		getline(cin, s);

		if (s == "EOI")	break;

		string str = make_all_upper(s);
		int temp = str.find("NEMO");
		if (temp>=0)	cout << "Found\n";
		else
			cout << "Missing\n";
	}

	return 0;
}