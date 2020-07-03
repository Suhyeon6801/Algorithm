#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> numbers;
	stack<char> op;
	string str, str2;
	bool minus = false;
	int ret = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			int j = i;
			while (isdigit(str[j]))
			{
				str2 += str[j];
				j++;
			}

			i = j;

			int num = stoi(str2);
			str2 = "";

			numbers.push(num);
			op.push(str[i]);

			if (!minus)
				ret += numbers.top();
			else
				ret -= numbers.top();

			if (op.top() == '-')
				minus = true;
		}
	}

	cout << ret << "\n";

	return 0;
}