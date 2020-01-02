#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int x, int y)
{
	return x > y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, s = 0;
	vector<int> a;
	vector<int> b;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		a.push_back(m);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		b.push_back(m);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), comp);

	for (int i = 0; i < n; i++)
	{
		s += a[i] * b[i];
	}

	cout << s << "\n";
	return 0;
}