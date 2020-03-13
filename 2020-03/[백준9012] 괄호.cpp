#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check(string s)
{
	stack <char> st;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')')
		{
			if (st.empty())
				return false;
			else
				st.pop();
		}
	}

	if (st.empty())	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string str;
		cin >> str;

		if (check(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}