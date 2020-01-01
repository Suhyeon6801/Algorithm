#include <iostream>
using namespace std;

const int MAX = 1000010;
long long int tree[MAX];
long long int n, m;

bool check(long long int x)
{
	long long int sum = 0;
	for (long long int i = 0; i < n; i++)
	{
		if (tree[i] - x >= 0)
			sum += (tree[i] - x);
		else
			sum += 0;
	}

	if (sum < m)	return true;
	else	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int start, end, mid;
	long long int getMax = -1;

	cin >> n >> m;
	for (long long int i = 0; i < n; i++)
	{
		cin >> tree[i];

		if (getMax < tree[i])	getMax = tree[i];
	}

	start = 0;
	end = getMax;

	while (start + 1 < end)
	{
		mid = (start + end) / 2;

		if (check(mid))	end = mid;
		else	start = mid;
	}

	cout << start << "\n";
}