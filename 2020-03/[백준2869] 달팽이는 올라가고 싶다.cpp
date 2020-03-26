#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double A, B, V;
	cin >> A >> B >> V;

	if (V == A)
		cout << "1\n";
	else
	{
		double h = V - A;
		long long days = ceil(h / (A - B));

		cout << days + 1<< "\n";
	}
	
	return 0;
}