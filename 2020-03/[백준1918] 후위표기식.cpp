#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<char> st;

	string infix, postfix = "";
	cin >> infix;

	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			st.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (!st.empty())
			{
				if (st.top() == '(')
				{
					st.pop();
					break;
				}
				cout << st.top();
				st.pop();
			}
		}
		else if (infix[i] == '*' || infix[i] == '/')
		{
			while (!st.empty()&&(st.top() == '*' || st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-' )
		{
			while (!st.empty() && st.top()!='(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(infix[i]);
		}
		else if (infix[i] >= 'A'&&infix[i] <= 'Z')
		{
			cout << infix[i];
		}
	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	

	return 0;
}