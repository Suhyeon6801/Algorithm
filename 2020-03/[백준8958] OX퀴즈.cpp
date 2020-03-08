#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int sum[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		memset(sum, 0, sizeof(sum));
		int result = 0;
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++)
		{
			if (i == 0)
			{
				if (str[i] == 'O')
					sum[i] = 1;
				else
					sum[i] = 0;
			}
			else
			{
				if (str[i] == 'O')
					sum[i] = sum[i - 1] + 1;
				else
					sum[i] = 0;
			}
		}
		
		for (int i = 0; i < str.length(); i++)
			result += sum[i];

		cout << result << "\n";
	}

	return 0;
}