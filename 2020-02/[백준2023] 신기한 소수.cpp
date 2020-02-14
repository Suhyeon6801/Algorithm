#include <iostream>
using namespace std;

int N;

bool isPrime(int num)
{
	if (num == 0 || num == 1)	return false;

	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0)
			return false;
	}

	return true;
}

void func(int num, int len)
{
	if (len == N)
	{
		cout << num << "\n";
		return;
	}

	for (int i = 1; i <= 9; i += 2)
	{
		int check = num * 10 + i;
		if (isPrime(check))
			func(check, len + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	func(2, 1);
	func(3, 1);
	func(5, 1);
	func(7, 1);	
	return 0;
}