#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	stack<char> st;

	cin >> str;

	int cnt = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			st.push(str[i]);
		else
		{
			st.pop();

			if (str[i - 1] == '(')
				cnt += st.size();
			else
				cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}