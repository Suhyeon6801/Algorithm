#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	cin >> N;

	int len = N.length();

	if (len == 1)
		cout << N << "\n";
	else
	{
		int result = 0;
		for (int i = 1; i < len; i++)
			result += i * (9 * pow(10, i - 1));

		result += len * (stoi(N) - pow(10, len - 1) + 1);
		cout << result << "\n";
	}

	return 0;
}