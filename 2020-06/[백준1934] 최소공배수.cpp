#include <iostream>
using namespace std;

int getGCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return getGCD(b, a%b);
}

int getLCM(int gcd, int a, int b)
{
	return gcd * (a / gcd)*(b / gcd);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int A, B;
		cin >> A >> B;
		cout << getLCM(getGCD(A,B),A, B) << "\n";
	}
	
	return 0;
}