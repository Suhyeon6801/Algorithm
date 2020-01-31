#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000010;
int prime[1000010] = { 0, };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	prime[1] = 1;
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		for (int j = i * i; j <= MAX; j += i)
		{
			prime[j] = 1;
		}
	}

	int M, N;
	cin >> M >> N;
	
	for (int i = M; i <= N; i++)
	{
		if (prime[i] == 0)
			cout << i << "\n";
	}
	
	return 0;
}