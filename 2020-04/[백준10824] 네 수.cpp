#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b, c, d;
	cin >> a >> b >> c >> d;

	a += b;
	c += d;

	long long temp1 = stoll(a);
	long long temp2 = stoll(c);

	cout << temp1 + temp2 << "\n";
	
	return 0;
}