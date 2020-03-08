#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char> st;
	int result = 0;
	string s;
	cin >> s;

	int temp = 1;
	bool flag = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
		{
			st.push(s[i]);
			temp *= 2;
		}
		else if (s[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				flag = false;
				break;
			}
			else
			{
				if (s[i - 1] == '(')
				{
					result+=temp;
				}
				temp /= 2;
				st.pop();
			}
		}
		else if (s[i] == '[')
		{
			st.push(s[i]);
			temp *= 3;
		}
		else if (s[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				flag = false;
				break;
			}
			else
			{
				if (s[i - 1] == '[')
				{
					result += temp;
				}
				temp /= 3;
				st.pop();
			}
		}
	}
	
	if (!flag || !st.empty())	cout << "0\n";
	else
	{
		cout << result << "\n";
	}

	return 0;;
}