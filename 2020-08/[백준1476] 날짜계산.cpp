#include <iostream>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int E, S, M;
	cin >> E >> S >> M;

	int a = 1, b = 1, c = 1;
	int cnt = 1;

	while (1)
	{
		if (a == E && b == S && c == M)	break;

		a++, b++, c++;
		cnt++;

		if (a > 15)	a = 1;
		if (b > 28)	b = 1;
		if (c > 19)	c = 1;
	}
	
	cout << cnt << "\n";

	return 0;
}