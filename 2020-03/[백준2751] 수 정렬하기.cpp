#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int,vector<int>, greater<int>> pq;
	int N, m;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> m;
		pq.push(m);
	}

	while (!pq.empty())
	{
		cout << pq.top() << "\n";
		pq.pop();
	}
	

	return 0;
}