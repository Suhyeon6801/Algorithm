#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	deque<int> dq;

	for (int i = 1; i <= N; i++)
		dq.push_back(i);

	while (!dq.empty())
	{
		if (dq.size() == 1)
		{
			cout << dq.front() << "\n";
			return 0;
		}

		dq.pop_front();
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	return 0;
}