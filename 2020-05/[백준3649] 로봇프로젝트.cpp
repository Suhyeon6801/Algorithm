#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, n;

	while (cin >> x >> n)
	{
		vector<int> v(n);
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		x = x * 10000000;

		sort(v.begin(), v.end());

		int left = 0, right = n - 1;
		while (left < right)
		{
			int sum = v[left] + v[right];

			if (sum == x)
			{
				flag = true;
				break;
			}
			else if (sum < x)
				left++;
			else
				right--;
		}

		if (flag)
			cout << "yes " << v[left] << " " << v[right] << "\n";
		else
			cout << "danger\n";
	}

	return 0;
}