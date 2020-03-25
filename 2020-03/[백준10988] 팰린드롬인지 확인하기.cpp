#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	stack<char> st;
	queue<char> que;

	for (int i = 0; i < str.length(); i++)
	{
		st.push(str[i]);
		que.push(str[i]);
	}

	bool flag = true;
	while (!st.empty())
	{
		if (st.top() != que.front())
		{
			flag = false;
			break;
		}
		st.pop();
		que.pop();
	}

	if (flag)	cout << "1\n";
	else
		cout << "0\n";

	return 0;
}