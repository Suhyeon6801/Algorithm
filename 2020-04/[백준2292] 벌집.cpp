#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N == 1)
		cout << "1\n";
	else
	{
		int idx = 1;
		while (1)
		{
			int a = 3 * (idx - 1)*idx + 1;
			int b = 3 * (idx + 1)* idx + 1;
			if (N<=b&&N>a)
			{
				cout << idx + 1 << "\n";
				break;
			}
			idx++;
		}
	}
	
	
	return 0;
}