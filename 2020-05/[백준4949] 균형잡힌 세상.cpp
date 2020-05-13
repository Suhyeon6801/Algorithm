#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	while (1)
	{
		getline(cin, str);

		if (str == ".")
			break;

		stack<char> st;
		bool flag = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				st.push(str[i]);
			else if (str[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
			else if (str[i] == ']')
			{
				if (!st.empty() &&st.top() == '[')
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
		}

		if (flag && st.empty())
			cout << "yes\n";
		else 
			cout << "no\n";

		while (!st.empty())
			st.pop();
	}
	
	return 0;
}