#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> s;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		s.insert(num);
	}

	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
	
	return 0;
}