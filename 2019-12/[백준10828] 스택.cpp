#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<int> st;

	int n, m;
	string command;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> m;
			st.push(m);
		}
		else if (command == "pop")
		{
			if (!st.empty())
			{
				cout << st.top() << "\n";
				st.pop();
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
		else if (command == "size")
		{
			cout << st.size() << "\n";
		}
		else if (command == "empty")
		{
			if (!st.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << "1" << "\n";
			}
		}
		else if (command == "top")
		{
			if (!st.empty())
			{
				cout << st.top() << "\n";
			}
			else
			{
				cout << "-1" << "\n";
			}
		}
	}
	
}