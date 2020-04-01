#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cout << v[0] * v[v.size() - 1] << "\n";

	return 0;
}