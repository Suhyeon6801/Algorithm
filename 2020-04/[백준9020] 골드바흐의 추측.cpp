#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int prime[10010] = { 0, };
struct Number {
	int n1, n2, diff;
};
vector<Number>v;

bool comp(Number num1, Number num2)
{
	return num1.diff < num2.diff;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	prime[0] = 1, prime[1] = 1;
	for (int i = 2; i <= sqrt(10010); i++)
	{
		for (int j = i * i; j < 10010; j += i)
		{
			prime[j] = 1;
		}
	}

	int T, n;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;

		for (int i = 2; i <=n; i++)
		{
			if (prime[i] == 0)
			{
				if (prime[n - i] == 0)
				{
					int temp = abs(i - (n - i));
					v.push_back({ i,n - i,temp });
				}
			}
		}

		sort(v.begin(), v.end(), comp);
		if (v[0].n1 < v[0].n2)
			cout << v[0].n1 << " " << v[0].n2 << "\n";
		else
			cout << v[0].n2 << " " << v[0].n1 << "\n";
		v.clear();
	}

	
	return 0;
}