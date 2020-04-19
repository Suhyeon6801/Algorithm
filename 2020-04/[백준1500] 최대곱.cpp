#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long ret = 1;
	int S, K;
	cin >> S >> K;

	while (1)
	{
		if (K == 1)
		{
			ret *= S;
			break;
		}

		ret *= S / K;
		S -= S / K;
		K--;
	}

	cout << ret << "\n";
	
	return 0;
}