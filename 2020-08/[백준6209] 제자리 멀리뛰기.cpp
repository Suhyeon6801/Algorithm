#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int d, n, m;

bool check(int len)
{
	int cnt = 0, idx = 0, gap;
	for (int i = 0; i < v.size(); i++)
	{
		gap = v[i] - idx;

		if (gap < len)	cnt++;
		else	idx = v[i];
	}

	if (cnt > m)	return true;
	else	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r;
	int start, end, mid;

	cin >> d >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> r;
		v.push_back(r);
	}
	v.push_back(d);

	if (n == m)
	{
		cout << d << "\n";
		return 0;
	}

	sort(v.begin(), v.end());

	start = 1, end = d;
	while (start + 1 < end)
	{
		mid = (start + end) / 2;

		if (check(mid))
			end = mid;
		else
			start = mid;
	}

	cout << start << "\n";

	return 0;
}

/*
25 5 5
2
14
11
21
17

--> 이거 정답 25
	
*/