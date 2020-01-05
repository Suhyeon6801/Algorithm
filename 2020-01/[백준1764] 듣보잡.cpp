#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;//듣지도 못한 사람

bool binarysearch(int start, int end, string s)
{
	if (start > end)	return false;
	else
	{
		int mid = (start + end) / 2;

		if (v[mid]==s)	return true;
		else if (v[mid]>s)	return binarysearch(start, mid - 1, s);
		else	return binarysearch(mid + 1, end, s);
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	string name;

	vector<string> result;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> name;
		v.push_back(name);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++)
	{
		cin >> name;

		if (binarysearch(0, n-1, name))
			result.push_back(name);
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}

	return 0;
}