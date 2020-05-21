#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 30;
int S[MAX];
int temp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 20; i++)
		temp[i] = i;

	int M, x;
	string cmd;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> cmd;

		if (cmd == "add")
		{
			cin >> x;

			if (S[x] == 0)
				S[x] = x;
			else
				continue;
		}
		else if (cmd == "remove")
		{
			cin >> x;

			if (S[x] != 0)
				S[x] = 0;
			else
				continue;
		}
		else if (cmd == "check")
		{
			cin >> x;
			if (S[x] != 0)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (cmd == "toggle")
		{
			cin >> x;
			if (S[x] == 0)
				S[x] = x;
			else
				S[x] = 0;
		}
		else if (cmd == "all")
		{
			for (int i = 1; i <= 20; i++)
				S[i] = temp[i];
		}
		else if (cmd == "empty")
		{
			memset(S, 0, sizeof(S));
		}
	}

	return 0;
}