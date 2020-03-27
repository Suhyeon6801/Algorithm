#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> que;
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		que.push(i);

	cout << "<";

	for (int i = 1; i <= N; i++)
	{
		while (!que.empty())
		{
			for (int j = 0; j < K - 1; j++)
			{
				que.push(que.front());
				que.pop();
			}
			
			if (que.size() == 1)
				cout << que.front() << ">";
			else
				cout << que.front() << ", ";

			que.pop();
		}
	}

	return 0;
}