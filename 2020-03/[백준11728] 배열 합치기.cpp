#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v;
	int N, M, k;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> k;
		v.push_back(k);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> k;
		v.push_back(k);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	

	return 0;
}