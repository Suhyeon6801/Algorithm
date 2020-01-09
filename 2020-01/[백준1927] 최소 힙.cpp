#include <iostream>
#include <queue>
#include <functional>
using namespace std;

const int MAX = 4001;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		if (m == 0)
		{
			if (pq.empty())	cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(m);
		
	}
	
	return 0;
}