#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int n;
	cin >> n;

	for (int i = 2; n > 1;)
	{
		if (n%i == 0)
		{
			cout << i << "\n";
			n /= i;
		}
		else
		{
			i++;
		}
	}

	
	return 0;
}