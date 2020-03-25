#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string first, str, result;
	cin >> N;

	cin >> first;

	result = first;
	for (int i = 1; i < N; i++)
	{
		cin >> str;

		for (int j = 0; j < first.length(); j++)
		{
			if (first[j] != str[j])
				result[j] = '?';
		}
	}

	cout << result << "\n";

	return 0;
}