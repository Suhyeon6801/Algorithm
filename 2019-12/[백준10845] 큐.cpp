#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue <int> que;

	int n, m;
	string command;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> m;
			que.push(m);
		}
		else if (command == "pop")
		{
			if (!que.empty())
			{
				cout << que.front() << "\n";
				que.pop();
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (command == "size")
		{
			cout << que.size() << "\n";
		}
		else if (command == "empty")
		{
			if (!que.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << "1\n";
			}
		}
		else if (command == "front")
		{
			if (!que.empty())
			{
				cout << que.front() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
		else if (command == "back")
		{
			if (!que.empty())
			{
				cout << que.back() << "\n";
			}
			else
			{
				cout << "-1\n";
			}
		}
	}
	
}