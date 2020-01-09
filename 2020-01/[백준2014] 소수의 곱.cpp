#include <iostream>
#include <queue>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

map<long long int, bool> check;
priority_queue<int, vector<long long int>, greater<long long int>> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[110];
	int k, n;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	long long int getMax = -1;
	pq.push(1);
	while (n--)
	{
		long long int cur = pq.top();
		pq.pop();

		for (int i = 0; i < k; i++)
		{
			long long int next = cur*arr[i];

			if (pq.size() <= n || getMax>=next) // next는 최대값보다 작거나 같은경우
			{
				if (!check[next])//중복검사
				{
					check[next] = true;
					pq.push(next);
					getMax = max(getMax, next);
				}
			}
		}
	}

	cout << pq.top() << "\n";
	
	return 0;;
}