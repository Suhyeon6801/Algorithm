#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//내림차순, first는 절대값, second는 원래수

	int N, x;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x;

		if (x != 0)
		{
			pq.push(make_pair(abs(x), x));
		}
		else
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
	}
	
	return 0;
}