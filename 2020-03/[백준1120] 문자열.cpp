#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string a, b;
	cin >> a >> b;

	int len_a = a.length();
	int len_b = b.length();
	int diff = len_b - len_a;
	int getMin = 100;

	for (int i = 0; i <= diff; i++)
	{
		int cnt = 0;
		for (int j = 0; j < len_a; j++)
		{
			if (a[j] != b[j + i])
				cnt++;
		}
		getMin = min(getMin, cnt);
	}
	
	cout << getMin << "\n";
	
	return 0;
}