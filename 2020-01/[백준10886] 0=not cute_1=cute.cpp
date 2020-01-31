#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	int zero = 0, one = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		if (M == 0)	zero++;
		else
			one++;
	}

	if (one > zero)
		cout << "Junhee is cute!\n";
	else
		cout << "Junhee is not cute!\n";
	
	return 0;
}