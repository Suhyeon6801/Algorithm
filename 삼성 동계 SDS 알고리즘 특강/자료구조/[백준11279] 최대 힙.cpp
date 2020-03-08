#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 4001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v(100010, { 0 });
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		if (m != 0)
		{
			v.push_back(m);
			push_heap(v.begin(), v.end());
		}
		else
		{
			cout << v[0] << "\n";
			pop_heap(v.begin(), v.end());
			v.pop_back();
		}
	}
	
	return 0;
}