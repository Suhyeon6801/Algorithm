#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int MAX = 2000010;
int prime[MAX] = { 0, };
string n;
int k;

bool division(int x)
{
	int ret = 0;
	for (int i = 0; n[i]; i++)//n이 너무 크니까 문자열로 처리해서 해결!
	{
		ret *= 10;
		ret += (n[i] - '0');
		ret %= x;
	}

	if (ret == 0)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= sqrt(MAX); i++)
	{
		for (int j = i*i; j <= MAX; j += i)
		{
			prime[j] = 1;
		}
	}

	cin >> n >> k;

	for (int i = 2; i < k; i++)
	{
		if (prime[i] == 0)
		{
			if (division(i))
			{
				cout << "BAD " << i << "\n";
				return 0;
			}
		}
	}
	cout << "GOOD\n";

	return 0;
}