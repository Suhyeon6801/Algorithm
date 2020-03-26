#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int loop[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> loop[i];

	sort(loop, loop + N, greater<int>());

	int getMax = -1;
	for (int i = 0; i < N; i++)
	{
		if (getMax < loop[i] * (i + 1))
			getMax = loop[i] * (i + 1);
	}

	cout << getMax << "\n";

	
	return 0;
}