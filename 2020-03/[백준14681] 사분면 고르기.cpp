#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;

	cin >> x >> y;

	if (x > 0 && y > 0)
		cout << "1\n";
	else if (x > 0 && y < 0)
		cout << "4\n";
	else if (x < 0 && y>0)
		cout << "2\n";
	else
		cout << "3\n";
	
	return 0;
}