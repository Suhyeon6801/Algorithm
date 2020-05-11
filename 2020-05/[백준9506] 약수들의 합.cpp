#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (1)
	{
		cin >> n;

		if (n == -1)
			break;

		int sum = 0;
		vector<int> v;
		for (int i = 1; i < n; i++)
		{
			if (n%i == 0)
			{
				sum += i;
				v.push_back(i);
			}
		}

		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < v.size(); i++)
			{
				if (i == v.size() - 1)
					cout << v[i] << "\n";
				else
					cout << v[i] << " + ";
			}
		}
		else
			cout << n << " is NOT perfect.\n";
	}
	
	return 0;
}